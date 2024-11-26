//
// Created by Ciska Vriezenga on 06/12/2022.
//

#ifndef BLOK2B_SINE_H
#define BLOK2B_SINE_H
#include "oscillator.h"

class Sine : public Oscillator {
public:
  Sine (float frequency = 0, float samplerate = 44100);

protected:
  void calculate();
};


#endif  //BLOK2B_SINE_H
