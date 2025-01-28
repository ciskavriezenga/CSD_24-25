#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator
{
public:
  //Constructor and destructor
  Saw();
  Saw(float frequency, float samplerate = 44100);
  ~Saw();

private:
  // calculate the next sample according to saw calculation
  void calcNextSample() override;

  // ---- values used to calculate the saw wave ----
  //phase increment
  const float phaseIncrement;
  // value used for smoothing the transition from -1 to 1
  float smoothY;
  //wrapped phase
  float wPhase;
};

#endif
