#include "tremolo.h"

Tremolo::Tremolo(float freq, float modDepth) :
  lfo(freq), modDepth(modDepth)
{
}

Tremolo::~Tremolo()
{}

void Tremolo::prepare(float sampleRate) {
  lfo.prepare(sampleRate);
}


float Tremolo::processFrame(float input)
{
  // retrieve modSignal in the range [0, 1]
  float modSignal = (lfo.genNextSample() + 1.0f) * 0.5f;

  // transform range [0, 1] --> [1 - modDepth, 1]
  modSignal *= modDepth;
  modSignal += 1.0f - modDepth;

  // apply tremolo
  return modSignal * input;
}

