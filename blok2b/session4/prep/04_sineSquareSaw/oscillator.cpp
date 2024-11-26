#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator(float frequency, float samplerate) : frequency(frequency),
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "Oscillator - constructor\n";
}


Oscillator::~Oscillator() {
  std::cout << "Oscillator - destructor\n";
}

void Oscillator::setSamplerate(float samplerate) {
  this->samplerate = samplerate;
}

float Oscillator::getSample() {
  return sample;
}

void Oscillator::tick() {
  phase += frequency / samplerate;
  // wrap the phase to interval [0, 1]
  if(phase > 1) phase -= 1.0;
  sample = sin(M_PI * 2 * phase) * amplitude;
}

//getters and setters
void Oscillator::setFrequency(float frequency)
{
  // TODO
  // add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}
