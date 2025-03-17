#pragma once

#include <iostream>
#include <juce_osc/juce_osc.h>
class CustomJuceOSC :  private juce::OSCReceiver, // [1]
                             private juce::OSCReceiver::ListenerWithOSCAddress<juce::OSCReceiver::MessageLoopCallback> // [2]
{
public:
  CustomJuceOSC();
  ~CustomJuceOSC();
};
