#include "callback.h"

CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), samplerate (sampleRate) {}

void CustomCallback::prepare (int rate) {
  samplerate = (float) rate;
  std::cout << "\nsamplerate: " << samplerate << "\n";
  tremolo.prepare (samplerate);
}

void CustomCallback::process (AudioBuffer buffer) {
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0; channel < numInputChannels; channel++) {
    for (auto i = 0; i < numFrames; i++) {
      buffer.outputChannels[channel][i] =
        tremolo.processFrame (buffer.inputChannels[channel][i]);
    }
  }
}
