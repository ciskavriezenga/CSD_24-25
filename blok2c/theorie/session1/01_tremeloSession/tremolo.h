#pragma once

#include <iostream>
#include <sine.h>

class Tremolo
{
public:
  Tremolo(float modFreq = 10.0f, float modDepth = 1.0f);
  ~Tremolo();
  float processFrame(float input);
  void setModDepth(float depth);
  void prepare(float samplerate);
  void setModFrequency(float freq);

private:
  Sine sine;
  float modDepth;
};
