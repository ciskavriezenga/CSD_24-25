# Initial Startup
## Prerequisites
- C++ Compiler works
  Windows: Visual Studio (niet code)
  MacOS: xcode
- CMake is installed
  Windows: https://cmake.org/download/
  MacOS: `brew install cmake`

## 1. Repo Initialisation
### Get JUCE
In the top level of your repository run the following to download the JUCE framework from github  
`git submodule add https://github.com/juce-framework/JUCE.git`
### Top Level CMakeLists.txt
In the same level as your JUCE folder, make a file called `cmakelists.txt`
It needs to be filled with something like this: 
```cmake
cmake_minimum_required(VERSION 3.20)  
project(MyProject LANGUAGES CXX) 

add_subdirectory(JUCE) # use add_subdirectory() to link folders
add_subdirectory(MyPlugin) # JUCE needs to go before your own JUCE projects
```

### Your Plugin Folder
Take a look in the JUCE folder  
Navigate to `Examples/CMake/AudioPlugin`   
Copy all the files and paste them into your `MyPlugin` folder   

Before we try building let's take a look at the CMakeLists.txt  
```cmake
project(MyPlugin VERSION 0.0.1)

juce_add_plugin(MyPlugin
    VERSION 0.0.1                              
    # ICON_BIG ...                              
    # ICON_SMALL ...
    COMPANY_NAME MyAwesomeCompany                         
    # IS_SYNTH TRUE/FALSE                       
    # NEEDS_MIDI_INPUT TRUE/FALSE               
    # NEEDS_MIDI_OUTPUT TRUE/FALSE              
    # IS_MIDI_EFFECT TRUE/FALSE                 
    # EDITOR_WANTS_KEYBOARD_FOCUS TRUE/FALSE    
    # COPY_PLUGIN_AFTER_BUILD TRUE/FALSE        
    PLUGIN_MANUFACTURER_CODE Daan               
    PLUGIN_CODE MyP1                            
      
    FORMATS AU VST3 Standalone                  
    PRODUCT_NAME "My Awesome Plugin")   
```
I have filled in all the things we will be using, feel free to ignore the rest for now.  

```cmake
target_sources(MyPlugin
    PRIVATE
        PluginEditor.cpp
        PluginProcessor.cpp)
```
This is where you add your `.cpp` files  

```cmake
target_link_libraries(MyPlugin
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
```
This is where you add your libraries  

### First build
in your terminal navigate to your top level project folder. (the one with the JUCE folder) and run this in your terminal `cmake -S . -B build`.   
This instructs cmake to generate your build scripts. The first time you do this this may take a a minute. `-S` is to get the location of the `Source` files, `.` is to indicate their location. `-B` is to instruct where to place the build (Binary) folder, in this example we're making a new folder called, `build`.   
When it is finished navigate to `build/MyPlugin`.   
To build:
- MacOS
  1. type `make` 
  2. you can find your binary in `MyPlugn_Artefacts`
- Windows
  1. type `cmake --build . --config debug`
  2. your binary is a little deeper, but you'll find it :- )

## 2. Making Your First Plugin! :- )!
For this example I will be using the Open Ladder Filter. Feel free to copy it, or use your own DSP.     
### PluginProcessor
The PluginProcessor is where you will be doing your audio calculations. The PluginProcessor keeps running even when the Graphical User Interface is closed. The following section will run you through how to implement your own audio effects.   
  
First let's make sure the includes are in order, and move down to the private section of the `PluginProcessor.h`.   
```cpp
private:
    
//==============================================================================
std::vector<MoogLadder> filters;
JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessor)
};
```
When using filters it is important that each audio channel has its own filter. We will be using a `std::vector` so we can dynamically increase the amount of filters to match the amount of audio channels.   
Onto the `PluginProcessor.h`. In the Constructor we will be placing back our filters per audio channel as follows: 
```cpp
AudioPluginAudioProcessor::AudioPluginAudioProcessor()
     : AudioProcessor (BusesProperties()
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                       )
{
	// for each input channel emplace one filter
	for(auto i = 0; i < getBusesLayout().getNumChannels(true, 0); ++i){  
	    filters.emplace_back();  
	    // Giving the filter some hardcoded start up params
	    filters[i].setCoefficients(MoogLadder::makeLoPass24());
	    // TODO Remove these when params are implemented
	    filters[i].setCriticalFrequency(500.0);
	    filters[i].setResonance(0.4);
	}
}
```
This `MoogLadder` expects you to call `prepare(sampleRate)` for it to work. Scroll down to the `void AudioPluginProcessor::PrepareToPlay()`. 
```cpp
void AudioPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	// We will be using a range based forloop to prepare 
	// each filter
	for(auto & filter : filters){
		filter.prepare(sampleRate);
	}
}
```

Up next is to implement the audio loop. You can find it in the `void AudioPluginAudioProcessor::processBlock()`. I have taken the liberty to clean out all of JUCE's comments, and I'll add my own for our simplicity
```cpp

void AudioPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                              juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused (midiMessages);

    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

	// the equivalent of your old audio callback :- )
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* writePointer = buffer.getWritePointer (channel); // input
		auto* readPointer = buffer.getReadPointer (channel); // output
		for(auto sample = 0; sample < buffer.getNumSamples(); ++sample){
			readPointer[sample] = filters[channel][sample].process(writePointer[sample]);
		}
    }
}

// secret: JUCE uses the same buffer for input and output 🤫
```
This should run. And if it's done correctly your sound should be filtered.   

## Controllable Parameters
Let's make it so we can control the cutoff and the resonance. Keeping in mind parameters have to be thread safe, to avoid data races we will be using `std::atomic`. 

```cpp
private:
    
//==============================================================================
std::atomic<float> *cutOff;
std::atomic<float> *resonance;

std::vector<MoogLadder> filters;
JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessor)
};
```

Next we have to register our parameters. This is so we can automate them within the DAW. To do this we will be using the `juce::AudioProcessorValueTreeState`, a huge data tree within JUCE, to handle our data quickly and relatively safely. 


```cpp
private:
    
//==============================================================================
std::atomic<float> *cutOff;
std::atomic<float> *resonance;

std::vector<MoogLadder> filters;
juce::AudioProcessorValueTreeState Params;
JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessor)
};
```
The `APVTS` has to be properly initialised. We will be doing this in the initialiser list of the PluginProcessor. 

```cpp
AudioPluginAudioProcessor::AudioPluginAudioProcessor()  
    : AudioProcessor (BusesProperties()  
#if ! JucePlugin_IsMidiEffect  
#if ! JucePlugin_IsSynth  
                          .withInput ("Input", juce::AudioChannelSet::stereo(), true)  
#endif  
                          .withOutput ("Output", juce::AudioChannelSet::stereo(), true)  
#endif  
    ), Params(*this, nullptr, "Parameters", {   std::make_unique<juce::AudioParameterFloat>(juce::ParameterID { "uCutoff", 1}, "Cutoff", 20.0, 20000.0, 500.0),  
                                                std::make_unique<juce::AudioParameterFloat>(juce::ParameterID { "uResonance", 1}, "Resonance", 0.0, 1.0, 0.1),  
                                            }  
 )
```
The `juce::AudioParameterFloat` requires atleast 5 parameters. 
1. Juce Parameter ID : this is the identifier to your parameter registry
2. Parameter Name: Visible to the user
3. Lowest possible value
4. Highest possible value
5. Initial value

The next step is to link these parameters to our atomics. We will be doing this in the body of our Processor constructor

```cpp
{
	// Use the parameter ID to return a pointer to our parameter data
	cutOff = Params.getRawParameterValue("uCutoff");  
	resonance = Params.getRawParameterValue("uResonance");
	
	// for each input channel emplace one filter
	for(auto i = 0; i < getBusesLayout().getNumChannels(true, 0); ++i){  
	    filters.emplace_back();  
	    // Giving the filter some hardcoded start up params
	    filters[i].setCoefficients(MoogLadder::makeLoPass24());
	    // TODO Remove these when params are implemented
	    filters[i].setCriticalFrequency(500.0);
	    filters[i].setResonance(0.4);
	}
}

```

Now that these are linked we can pass these values to the setters of the filter. That will be done in the `processBlock()`
```cpp

void AudioPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                              juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused (midiMessages);
	// this will be updated everytime the processBlock is called. 
	// the rate at which this occurs is synonymous to control rate
	for(auto & filter : filters){
		filter.setCriticalFrequency(*cutOff);
		filter.setResonance(*resonance);
	}
	
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

	// the equivalent of your old audio callback :- )
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* writePointer = buffer.getWritePointer (channel); // input
		auto* readPointer = buffer.getReadPointer (channel); // output
		for(auto sample = 0; sample < buffer.getNumSamples(); ++sample){
			writePointer[sample] = filters[channel].process(readPointer[sample]);
		}
    }
}
```

The Final step to completing the parameter registration is implementing the `getStateInformation()` and the `setStateInformation()`. This part may seem a bit abstract, a lot of the heavy lifting is covered by JUCE's behind the scenes functionality. We can coast off of that and pray that it all works as expected. 

```cpp
void AudioPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData) {  
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    auto state = Params.copyState();  
    std::unique_ptr<juce::XmlElement> xml (state.createXml());  
    copyXmlToBinary (*xml, destData);  
}  
```
```cpp
void AudioPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes) {  
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));  
    if (xmlState.get() != nullptr)  
        if (xmlState->hasTagName (Params.state.getType()))  
            Params.replaceState (juce::ValueTree::fromXml (*xmlState));  
}
```

## 3.  Run it in your DAW! ! !
After building, you will be able to find the VST3 or the AU in the folders mentioned in step 1. Simply copy it into the folder where you store your Plugins and your DAW should find it :- ). 



