#pragma once

#include <iostream>
#include "sine.h"

class Tremolo
{
public:
  Tremolo(float freq, float modDepth);
  ~Tremolo();

  void prepare(float samplerate);
  float processFrame(float sample);

  // setters and getters
  void setModFreq(float freq);

private:
  float modDepth;
  Sine sine;

  // hide default constructor
  Tremolo(){}
};
