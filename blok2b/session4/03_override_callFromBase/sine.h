#pragma once

#include <iostream>
#include "oscillator.h"

class Sine : public Oscillator
{
public:
  Sine();
  ~Sine();

  //override calculate from base class
  void calculate();
};
