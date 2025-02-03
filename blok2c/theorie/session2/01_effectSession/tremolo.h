#pragma once

#include <iostream>
#include "sine.h"
#include "effect.h"

class Tremolo : public Effect
{
public:
  Tremolo(float freq = 1.0f, float modDepth = 1.0f, float dryWet = 1.0f);
  ~Tremolo();

  void prepare(float samplerate) override;

  // setters and getters
  void setModFreq(float freq);

private:
  float modDepth;
  Sine sine;
  float applyEffect(float sample) override;
  // hide default constructor
  Tremolo(){}
};
