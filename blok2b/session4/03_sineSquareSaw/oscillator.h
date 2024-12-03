#ifndef _Oscillator_H_
#define _Oscillator_H_
#include <iostream>

class Oscillator {
public:
  Oscillator (float frequency = 0, float samplerate = 44100);
  ~Oscillator();

  // allow to set samplerate after initialization
  void setSamplerate (float samplerate);
  //return the current sample
  float getSample();
  // go to next sample
  void tick();
  // calculate next sample (pure virtual)
  virtual void calculate() = 0;

  //getters and setters
  void setFrequency (float frequency);
  float getFrequency();

protected:
  float sample;
  float phase;
  float amplitude;
private:
  float frequency;
  // sample contains the current sample
  float samplerate;
};

#endif
