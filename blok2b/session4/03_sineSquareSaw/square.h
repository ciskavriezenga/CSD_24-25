#ifndef _SQUARE_H_
#define _SQUARE_H_
#include "oscillator.h"

class Square : public Oscillator {
public:
  Square(float frequency = 0, float samplerate = 44100);
  ~Square();

  //override calculate from base class
  void calculate();
};


#endif  //SQUARE_H_
