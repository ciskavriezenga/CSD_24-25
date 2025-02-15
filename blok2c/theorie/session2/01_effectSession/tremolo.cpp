#include "tremolo.h"

Tremolo::Tremolo(float freq, float modDepth) :
  modDepth(modDepth), sine(freq)
{}

Tremolo::~Tremolo() {}

void Tremolo::prepare(float samplerate) {
  // NOTE: example, keeping things 'simple', hence no validation
  sine.prepare(samplerate);
}

void Tremolo::applyEffect(const float& input, float& output) {
  // transform sine in range [-1, 1] to range [0, 1]
  float modSignal = sine.genNextSample();
  // apply modDept
  modSignal *= modDepth;
  modSignal += 1.0 - modDepth;
  // apply modulation signal to input
  output = input * modSignal;
}

void Tremolo::setModFreq(float freq) {
  // NOTE: example, keeping things 'simple', hence no validation
  sine.setFrequency(freq);
}

