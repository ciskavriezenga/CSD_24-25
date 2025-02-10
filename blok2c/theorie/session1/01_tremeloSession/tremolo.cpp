#include "tremolo.h"

Tremolo::Tremolo(float modFreq, float modDepth)
  : modDepth(modDepth)
{
  setModFrequency(modFreq);
}

Tremolo::~Tremolo()
{}

void Tremolo::setModFrequency (float freq) {
  if(freq >= 0.0f && freq <= 20.0f) {
    sine.setFrequency(freq);
  } else {
    std::cout << "\nTremolo::setFrequency - Incorrect frequency\n";
  }
}

float Tremolo::processFrame (float input) {
  float modSignal = sine.getSample();

  // transform range [-1, 1] to [0,1]
  // -0.5 to shift the phase 0.5, due to the phase shift
  // that occurs by applying the modDepth
  modSignal = modSignal * -0.5f + 0.5f;

  // transform to range [0, modDepth]
  modSignal = modSignal * modDepth;
  //transform to range [1 - modDepth, 1]
  modSignal = 1.0f - modSignal;

  input *= modSignal;
  // 'tick' the sine to the next sample
  sine.genNextSample();

  return input;
}

void Tremolo::prepare(float samplerate) {
  std::cout << "\nHI THERE THIS SHOULD BE CALLED\n";
  sine.prepare(samplerate);
}

void Tremolo::setModDepth (float depth) {
  if(depth >= 0 && depth <=1) {
    modDepth = depth;
  } else {
    std::cout << "\nTremolo::setModDepth - Incorrect modDepth\n";
  }
}