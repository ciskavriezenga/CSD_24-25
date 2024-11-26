#pragma once

#include "oscillator.h"
#include <iostream>

class Saw : public Oscillator {
public:
  Saw();
  ~Saw();

  //override calculate from base class
  void calculate();
};
