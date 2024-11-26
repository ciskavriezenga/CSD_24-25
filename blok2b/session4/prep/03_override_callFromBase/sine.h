#pragma once

#include "oscillator.h"
#include <iostream>

class Sine : public Oscillator {
public:
  Sine();
  ~Sine();

  //override calculate from base class
  void calculate();
};
