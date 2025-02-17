#include "callback.h"

CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), samplerate (sampleRate) {
  std::cout << "Hallo Ciska" << std::endl;
}

void CustomCallback::prepare (int rate) {
  samplerate = (float) rate;
  oscillator.setSamplerate (samplerate);
  std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process (AudioBuffer buffer) {
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0u; channel < numOutputChannels; ++channel) {
    for (int sample = 0u; sample < numFrames; ++sample) {
      outputChannels[channel][sample] = 0.0f;
      outputChannels[channel][sample] = oscillator.getSample();
      oscillator.tick();
    }
  }
}
