#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>
#include "oscillator.h"

class Square : public Oscillator
{
public:
  //Constructor and destructor
  Square();
  Square(float frequency, float samplerate = 44100);
  ~Square();

private:
  // calculate the next sample according to square calculation
  void calcNextSample() override;
};

#endif
