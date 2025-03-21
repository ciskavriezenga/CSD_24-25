#include "callback.h"


CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), samplerate (sampleRate) {}

void CustomCallback::prepare (int rate) {
  samplerate = (float) rate;
  std::cout << "\nsamplerate: " << samplerate << "\n";

  oscServer.init (serverport);
  oscServer.set_callback ("/sound", "siii");
  oscServer.set_callback ("/tactile", "ii");
  oscServer.set_callback ("/box/setstatus", "iii");
  oscServer.set_callback ("/note-on", "iii");

  oscServer.start();
  std::cout << "OSC Server listening on port: " << serverport << std::endl;
}

void CustomCallback::process (AudioBuffer buffer) {
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;
  float sample;
  for (int channel = 0u; channel < numInputChannels; channel++) {
    for (int i = 0u; i < numFrames; i++) {
      sample = inputChannels[channel][i];
      outputChannels[channel][i] = 0;
    }
  }
}
