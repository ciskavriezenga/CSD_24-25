#include "saw.h"


Saw::Saw() : Oscillator()
{
  std::cout << "• Saw::Saw\n";
}

Saw::~Saw()
{
  std::cout << "• Saw::~Saw\n";
}

void Saw::calculate()
{
  std::cout << "• Saw::calculate\n";
}
