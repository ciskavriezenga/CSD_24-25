#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>

#define SAMPLERATE 44100

class Sine
{
public:
  //Constructor and destructor
  Sine(float frequency);
  ~Sine();

  //return the current sample
  float getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

  //NOTE - do we need a setter for phase? for now -> not using one

private:
  float frequency;
  float phase = 0;
  // contains the current sample
  float sample = 0;
};

#endif
