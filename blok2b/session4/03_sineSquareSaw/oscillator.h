#ifndef _Oscillator_H_
#define _Oscillator_H_
#include <iostream>

class Oscillator
{
public:
  Oscillator(float frequency= 0, float samplerate = 44100);
  ~Oscillator();

  // allow to set samplerate after initialization
  void setSamplerate(float samplerate);
  //return the current sample
  float getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

private:
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  float samplerate;
};

#endif
