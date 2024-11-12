#include "oscillator.h"


// delegating constructor
Oscillator::Oscillator() : Oscillator(220, 0) // default frequency
{
  std::cout << "Inside Oscillator constructor ()\n";
}

// initializer list:  used to directly initialize data members of a class.
Oscillator::Oscillator(float frequency, float amp)
    : freq(frequency), amp(amp)
{
  std::cout << "Inside Oscillator constructor (frequency)\n";
}

Oscillator::~Oscillator()
{
  std::cout << "Inside Oscillator destructor\n";
}


// setters and getters
void Oscillator::setFreq(float freq)
{
  if(freq > 0 && freq < 22050) {
    this->freq = freq;
  } else {
    std::cout << "The frequency value is incorrect"
    << " please present a value in the interval [0, 22049]\n";
  }
}

float Oscillator::getFreq()
{
  return freq;
}
