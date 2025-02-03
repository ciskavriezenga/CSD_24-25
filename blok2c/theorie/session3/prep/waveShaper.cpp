#include "waveShaper.h"
#include <iostream>

WaveShaper::WaveShaper(float dryWet) : Effect(dryWet) {}

WaveShaper::~WaveShaper() {}


void WaveShaper::prepare(float samplerate) {
  // TODO - do we need this?
}


float WaveShaper::applyEffect(const float input)
{
  // TODO - implement functionality
  // simple pass through for now
  return input;
}

