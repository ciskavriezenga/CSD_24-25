#include "sine.h"


Sine::Sine() : Oscillator()
{
  std::cout << "• Sine::Sine\n";
}

Sine::~Sine()
{
  std::cout << "• Sine::~Sine\n";
}

void Sine::calculate()
{
  std::cout << "• Sine::calculate\n";
}
