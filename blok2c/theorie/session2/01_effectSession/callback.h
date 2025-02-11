#ifndef CALLBACK_H
#define CALLBACK_H

#include <audiocomponent.h>
#include "tremolo.h"
#include "delay.h"


class CustomCallback : public AudioCallback {
public:
  CustomCallback (float sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float samplerate;
  Tremolo tremolo {6, 1};
  Delay delay {48000, 48000 * 2};
};

#endif //CALLBACK_H
