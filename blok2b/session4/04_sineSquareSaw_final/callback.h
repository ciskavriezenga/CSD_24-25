#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"
#include "../04_sineSquareSaw/sine.h"
#include "../04_sineSquareSaw/square.h"

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  //Sine sine = Sine(440, samplerate);
  Square square = Square(440, samplerate);
};

#endif //CALLBACK_H
