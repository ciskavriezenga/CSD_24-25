#pragma once

#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator
{
public:
  Saw();
  ~Saw();

  //override calculate from base class
  void calculate();
};
