#include <iostream>

class Oscillator {
public:
  Oscillator();
  Oscillator(float frequency);
  ~Oscillator();

  float freq;
};


// delegating constructor
Oscillator::Oscillator() : Oscillator(220) // default frequency
{
  std::cout << "Inside Oscillator constructor ()\n";
}

Oscillator::Oscillator(float frequency) : freq(frequency)
{
  std::cout << "Inside Oscillator constructor (frequency)\n";
}

Oscillator::~Oscillator()
{
  std::cout << "Inside Oscillator destructor\n";
}



int main ()
{
  std::cout << "\nin main\n";
  Oscillator osc;
  std::cout << "02_oscillator's frequency: " << osc.freq << "\n";
  return 0;
}
