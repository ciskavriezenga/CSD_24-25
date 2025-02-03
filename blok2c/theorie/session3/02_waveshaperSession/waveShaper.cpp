#include "waveShaper.h"
#include "wavetableGenerator.h"
#include <iostream>

WaveShaper::WaveShaper(float dryWet) : Effect(dryWet) {
  WavetableGenerator::generateSCurve(buffer, BUFFER_SIZE, 10.0f);

}

WaveShaper::~WaveShaper() {}


float WaveShaper::applyEffect(const float input)
{
  float sample = input;
  if(sample > 0.99999999f)  sample = 0.99999999f;
  if(sample < -0.99999999f)  sample = -0.99999999f;
  float indexFloat = WavetableGenerator::map(sample, -1.0f, 1.0f, 0.0f, (float) (BUFFER_SIZE - 1));
  //float indexFloat = mapInRange(sample, -1.0f, 1.0f, 0.0f, (float) (BUFFER_SIZE - 1));
  int index = (int) indexFloat;
  return buffer[index];
}

