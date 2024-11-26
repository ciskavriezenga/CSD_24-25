#ifndef CALLBACK_H
#define CALLBACK_H

#include "audiocomponent.h"
#include "oscillator.h"
#include "sine.h"
#include "square.h"

class CustomCallback : public AudioCallback {
public:
  CustomCallback (float sampleRate);
  void prepare (int rate) override;
  void process (AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  Square oscillator { 220, samplerate };
  //    Sine oscillator {440, samplerate};
};

#endif  //CALLBACK_H
