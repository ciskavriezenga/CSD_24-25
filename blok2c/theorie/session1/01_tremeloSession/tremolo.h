#pragma once

#include <iostream>
#include "sine.h"

class Tremolo
{
public:
  Tremolo(float freq, float modDepth);
  ~Tremolo();
  float processFrame(float input);
  void prepare(float sampleRate);

private:
  Sine lfo;
  float modDepth;
};
