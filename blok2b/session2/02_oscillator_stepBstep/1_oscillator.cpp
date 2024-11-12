#include <iostream>

class Oscillator {
public:
  Oscillator();
  ~Oscillator();
};


Oscillator::Oscillator()
{
  std::cout << "Inside Oscillator constructor\n";
}

Oscillator::~Oscillator()
{
  std::cout << "Inside Oscillator destructor\n";
}



int main()
{
  std::cout << "\nin main\n";
  Oscillator osc;
  return 0;

}
