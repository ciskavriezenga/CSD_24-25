#ifndef _SINE_H_
#define _SINE_H_
#include "oscillator.h"

class Sine : public Oscillator {
public:
  Sine(float frequency = 0, float samplerate = 44100);
  ~Sine();

  //override calculate from base class
  void calculate();
};


#endif  //SINE_H_
