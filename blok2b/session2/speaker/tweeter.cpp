#include <iostream>
#include "tweeter.h"

Tweeter::Tweeter()
{
}

void Tweeter::move(float coilPosition)
{
  this->coilPosition = coilPosition;
  std::cout << "Tweeter coil position: " << coilPosition << std::endl;
}

void Tweeter::setImpedance(int impedance)
{
  this->impedance = 2 * impedance;
  coilPosition = 0;
}

int Tweeter::getImpedance()
{
  return impedance;
}

