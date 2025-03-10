#include "tremolo.h"

Tremolo::Tremolo(float freq, float modDepth) :
  modDepth(modDepth), sine(freq)
{}

Tremolo::~Tremolo() {}

void Tremolo::prepare(float samplerate) {
  // NOTE: example, keeping things 'simple', hence no validation
  sine.prepare(samplerate);
}

float Tremolo::processFrame(float sample) {
  // transform sine in range [-1, 1] to range [0, 1]
  // -0.5 to shift the phase 0.5, due to the phase shift
  // that occurs by applying the modDepth
  float modSignal = sine.genNextSample() * -0.5 + 0.5;
  // apply modDept
  modSignal *= modDepth;
  modSignal += 1.0 - modDepth;
  // apply modulation signal to input
  return sample * modSignal;
}

void Tremolo::setModFreq(float freq) {
  // NOTE: example, keeping things 'simple', hence no validation
  sine.setFrequency(freq);
}

