# Terugblik 

• when allocating objects in a dynamic manner, don't forget the call to delete! 

• modulairity --> what comes where? When you view the code from the perspective of the model-view-controller pattern, a Synth should not be aware of things like MIDI or OSC. Same goes for a Melody class, a Synth should not be dependent on such a class. 

• verify the input in methods --> setFrequency(freq), the application should check iff it is a valid value. However, sometimes multiple options are possible. E.g. how about the amplitude of an oscillator? In case you want the Oscillator to be able alter the amplitude of the output sample, one might prefer the range of [-1, 1]. But how about LFO's that you want to use to transform other signals / parameters? Different viewpoints and different usage can result in different choices, architectures and implementations!    

• Private & prototected members please! Carefully consider if methods should be public or can stay private!

• When using stl containers like vectors, please check how to use these. What happens when you e.g. push back a field of a class multiple times (it gets copied, field itself stays unused?). Another example, when you require the size of the vector, better not cache it in a field, but simply 're-ask the vector'.   

• "Mind your step" -- Where should you 'tick' the audio classes to the next sample? Not inside the inner channel forloop!

• 
