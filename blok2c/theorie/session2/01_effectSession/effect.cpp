#include "effect.h"
#include <iostream>

Effect::Effect(float dryWet) {
  setDryWet(dryWet);
  // NOTE: we want to prevent dryWet exceeding [0, 1] range
  // thus use a setDryWet(dryWet) method
}

Effect::~Effect() {}


float Effect::processFrame(float input) {
  float output = applyEffect(input);

#if 0    // Example code - exactly the same as two lines below
  float wetOutput = output * wet;
  float dryOutput = input * dry;
  output = wetOutput + dryOutput;
#endif

  // apply dry wet
  output *= wet;
  output += input * dry;

  return output;
}


void Effect::setDryWet(float dryWet) {
  if(dryWet >=0.0f && dryWet <= 1.0f) {
    // dryWet refers to the wet value, thus dryWet = 1 --> wet = 1
    wet = dryWet;
    dry = 1.0f - dryWet;
  } else {
    // TODO log error
  }
}