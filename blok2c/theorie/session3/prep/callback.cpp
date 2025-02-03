#include "callback.h"
#include <iostream>

CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), samplerate (sampleRate) {}

void CustomCallback::prepare(int rate) {
  samplerate = (float) rate;
  std::cout << "\nsamplerate: " << samplerate << "\n";
  // TODO - call prepare waveshaper if necessary
}

void CustomCallback::process(AudioBuffer buffer) {
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

  for (int channel = 0u; channel < numInputChannels; channel++) {
    for (int i = 0u; i < numFrames; i++) {
      // TODO - implement waveShaper
      outputChannels[channel][i] = 0;
    }
  }
}

