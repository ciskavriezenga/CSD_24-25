#pragma once

#include <iostream>
#include "effect.h"
#include "sine.h"

class Tremolo : public Effect
{
public:
  Tremolo(float freq, float modDepth);
  ~Tremolo();

  void prepare(float samplerate) override;

  void applyEffect(const float& input, float& output) override;
  // setters and getters
  void setModFreq(float freq);

private:
  float modDepth;
  Sine sine;

  // hide default constructor
  Tremolo(){}
};
