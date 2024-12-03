#include "square.h"
#include "math.h"


Square::Square() : frequency(220.0),
  amplitude(1.0), phase(0), sample(0), samplerate(44100.0)
{
  std::cout << "Square - constructor\n";
}


Square::Square(double frequency, double samplerate) : frequency(frequency),
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "Square - constructor\n";
}



Square::~Square() {
  std::cout << "Square - destructor\n";
}


double Square::getSample() {
  return sample;
}

void Square::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  // wrap the phase so it stays in the interval [0, 1]
  if(phase > 1) phase -= 1.0;
  // use the phase to calculate the next value of the square wave
  if(phase < 0.5) {
    sample = 1.0;
  } else {
    sample = -1.0;
  }
  sample *= amplitude;
}

//getters and setters
void Square::setFrequency(double frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

double Square::getFrequency()
{
  return frequency;
}
