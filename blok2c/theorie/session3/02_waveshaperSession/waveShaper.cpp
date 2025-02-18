#include "waveShaper.h"
#include "wavetableGenerator.h"
#include <iostream>

WaveShaper::WaveShaper(float dryWet) : Effect(dryWet) {
  WavetableGenerator::generateSCurve(buffer, BUFFER_SIZE, 100.0f);

}

WaveShaper::~WaveShaper() {}


float WaveShaper::applyEffect(const float input)
{
  float sample = input;
  if(sample > 1.0f)  sample = 1.0f;
  if(sample < -1.0f)  sample = -1.0f;
  float indexFloat = WavetableGenerator::map(sample, -1.0f, 1.0f, 0.0f, (float) (BUFFER_SIZE - 1));
  int index = (int) indexFloat;
  // TODO - interpolate!
  return buffer[index];
}

