#include "callback.h"


void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";
    sine.prepare(rate);
}

void CustomCallback::process(AudioBuffer buffer) {
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

  for (int channel = 0u; channel < numOutputChannels; channel++) {
    for (int i = 0u; i < numFrames; i++) {
      // TODO - add Tremelo
      buffer.outputChannels[channel][i] = sine.genNextSample();
    }
  }

}
