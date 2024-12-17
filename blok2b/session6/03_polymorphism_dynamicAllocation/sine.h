#pragma once

#include <iostream>
#include "oscillator.h"

class Sine : public Oscillator
{
public:
  Sine() {std::cout << "Sine::Sine -- constructor\n";}
  ~Sine() {std::cout << "Sine::~Sine -- destructor\n";}

  //override calculate from base class
  void calculate() {std::cout << "Sine::calculate\n";}
};
