#include "oscillator.h"

Oscillator::Oscillator(float frequency) :
Oscillator(frequency, 44100) {}

Oscillator::Oscillator(float frequency, float samplerate) :
  frequency(frequency),  phase(0), sample(0),amplitude(1.0),
  samplerate(samplerate)
  {}

Oscillator::~Oscillator() {}

void Oscillator::prepare(float samplerate)
{
  this->samplerate = samplerate;
}

// generates and returns the next sample
float Oscillator::genNextSample() {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;

  // wrap the phase so it stays in the interval [0, 1]
  if(phase > 1) phase -= 1.0;

  // let subclasses calculate the next sample
  calcNextSample();

  // apply amplitude
  sample *= amplitude;

  // return the newly generated sample
  return sample;
}

// ---- getters and setters -----

// returns current sample
float Oscillator::getSample() {
  return sample;
}

void Oscillator::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}
