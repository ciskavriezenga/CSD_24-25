#ifndef CALLBACK_H
#define CALLBACK_H

#include <audiocomponent.h>
#include "osc_server.h"

class CustomCallback : public AudioCallback {
public:
  CustomCallback (float sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  LocalOSC oscServer;
  std::string serverport {"7777"};

};

#endif //CALLBACK_H