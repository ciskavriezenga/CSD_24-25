#include "effect.h"
#include <iostream>

Effect::Effect(float dryWet) {
  // NOTE: we want to prevent dryWet exceeding [0, 1] range
  // thus use a setDryWet(dryWet) method
}

Effect::~Effect() {}

void Effect::processFrame(const float& input, float& output) {
  // TODO bypass
  applyEffect(input, output);
  // TODO dryWet
}
