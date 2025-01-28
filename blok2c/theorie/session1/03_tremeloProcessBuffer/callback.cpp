#include "callback.h"


void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";
    tremolo.prepare(rate);
}

void CustomCallback::process(AudioBuffer buffer) {
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

  tremolo.process(inputChannels[0], outputChannels[0], numFrames);
}

