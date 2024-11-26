#include <iostream>
#include "oscillator.h"


/*
 * ___ constructor delegation ___
 * call the other constructor with default values
 * this allows to create a oscillator object with the default Constructor
 * Oscillator osc;
 * but we ensure the default values are set, without the need to maintain
 * two constructors --> we simply use just one constructor for the actual
 * initialization.
 */
Oscillator::Oscillator() : Oscillator(220, 0.5) {}

/*
 * ___ initializer list ___
 * using initializer list to set frequency
 */
Oscillator::Oscillator(float freq, float amp) : freq(freq), amp(amp)
{
  std::cout << "\n* Oscillator::Oscillator - constructor\n";
  count++;
}

Oscillator::~Oscillator()
{
  std::cout << "\n* Oscillator::~Oscillator - destructor\n";
  count--;
}

void Oscillator::setFrequency(float freq)
{
  if(freq >= 0) { //and also check < halfSamplerate
    this->freq = freq;
  } else {
    throw "Oscillator::setFrequency does not except negative numberes";
  }
}

float Oscillator::getFrequency() { return freq; }

void Oscillator::setAmp(float amp) { this->amp = amp; }

float Oscillator::getAmp() { return amp;}

void Oscillator::displayCount()
{
  std::cout << "\nCount: " << count << std::endl;
}
// initialize count field
int Oscillator::count = 0;
