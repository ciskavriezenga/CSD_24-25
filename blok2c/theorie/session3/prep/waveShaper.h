#pragma once
#include "effect.h"

class WaveShaper : public Effect{
public:
  WaveShaper(float dryWet = 1.0);
  ~WaveShaper();

  void prepare(float samplerate) override;

  // override base class method
  // applies tremolo effect to the input frame
  float applyEffect(const float input) override;
private:
  // hide default constructor
  WaveShaper();
};

