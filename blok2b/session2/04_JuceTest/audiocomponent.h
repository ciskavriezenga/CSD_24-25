//
// Created by Dean on 02/12/2023.
//

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_audio_devices/juce_audio_devices.h>


struct AudioBuffer {
    const float** inputChannels;
    float** outputChannels;
    int numInputChannels, numOutputChannels, numFrames;

private:

};

class AudioCallback : public juce::AudioSource {
public:
    AudioCallback(double sampleRate) : Fs (sampleRate) {

    }

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override {
        juce::ignoreUnused(samplesPerBlockExpected);
        Fs = sampleRate;
        prepare(static_cast<int>(Fs));
    }
    void releaseResources() override {}
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override {
      processBlock(bufferToFill);
    }

    virtual void process(AudioBuffer buffer) = 0;
    virtual void prepare(int sampleRate) = 0;

private:
    double Fs;

    void processBlock(const juce::AudioSourceChannelInfo& bufferToFill) {
        const auto buffer = AudioBuffer {
            .inputChannels = const_cast<const float**> (bufferToFill.buffer->getArrayOfReadPointers()),
            .outputChannels = const_cast<float **>( bufferToFill.buffer->getArrayOfWritePointers()),
            .numInputChannels = bufferToFill.buffer->getNumChannels(),
            .numOutputChannels = bufferToFill.buffer->getNumChannels(),
            .numFrames = bufferToFill.buffer->getNumSamples()
        };
        process(buffer);
    }

};

struct ScopedMessageThreadEnabler {
    ScopedMessageThreadEnabler() { juce::initialiseJuce_GUI(); }
    ~ScopedMessageThreadEnabler() { juce::shutdownJuce_GUI(); }
};


class JUCEModule {
public:
    explicit JUCEModule(AudioCallback& callback) : _callback(callback){
        audioSourcePlayer.setSource (&_callback);
        audioDeviceManager.addAudioCallback (&audioSourcePlayer);
    }

    ~JUCEModule() {
        audioDeviceManager.removeAudioCallback (&audioSourcePlayer);
    }

    void init(int numInputChannels, int numOutputChannels){
        audioDeviceManager.initialiseWithDefaultDevices(numInputChannels, numOutputChannels);
    }

private:
    AudioCallback& _callback;
    juce::AudioDeviceManager audioDeviceManager;
    juce::AudioSourcePlayer audioSourcePlayer;
};
