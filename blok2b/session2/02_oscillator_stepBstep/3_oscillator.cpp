#include <iostream>

class Oscillator {
public:
  Oscillator();
  Oscillator(float frequency);
  ~Oscillator();

  float getFreq();
  void setFreq(float freq);

private:
  float freq;
};


// delegating constructor
Oscillator::Oscillator() : Oscillator(220) // default frequency
{
  std::cout << "Inside Oscillator constructor ()\n";
}

// initializer list:  used to directly initialize data members of a class.
Oscillator::Oscillator(float frequency) : freq(frequency)
{
  std::cout << "Inside Oscillator constructor (frequency)\n";
}

Oscillator::~Oscillator()
{
  std::cout << "Inside Oscillator destructor\n";
}

float Oscillator::getFreq()
{
  return freq;
}

void Oscillator::setFreq(float freq)
{
  this->freq = freq;
}



int main ()
{
  std::cout << "\nin main\n";
  Oscillator osc;
  std::cout << "02_oscillator's frequency: " << osc.getFreq() << "\n";
  osc.setFreq(440);
  std::cout << "02_oscillator's frequency: " << osc.getFreq() << "\n";

  return 0;
}
