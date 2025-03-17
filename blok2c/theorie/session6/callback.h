#ifndef CALLBACK_H
#define CALLBACK_H

#include <audiocomponent.h>
#include "tremolo.h"


class CustomCallback : public AudioCallback {
public:
  CustomCallback (float sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  CustomJuceOSC juceOSC = CustomJuceOSC();
};

#endif //CALLBACK_H