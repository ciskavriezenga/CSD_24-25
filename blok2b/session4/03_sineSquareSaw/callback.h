#ifndef CALLBACK_H
#define CALLBACK_H

#include "audiocomponent.h"
#include "oscillator.h"

class CustomCallback : public AudioCallback {
public:
  CustomCallback (float sampleRate);
  void prepare (int rate) override;
  void process (AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  Oscillator oscillator { 220, samplerate };
};

#endif  //CALLBACK_H
