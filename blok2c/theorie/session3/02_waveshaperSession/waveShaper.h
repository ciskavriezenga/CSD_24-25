#pragma once
#include "effect.h"

#define BUFFER_SIZE 512

class WaveShaper : public Effect{
public:
  WaveShaper(float dryWet = 1.0);
  ~WaveShaper();

  // override base class method
  // applies tremolo effect to the input frame
  float applyEffect(const float input) override;

private:
  // hide default constructor
  WaveShaper();
  float buffer[BUFFER_SIZE];
};

