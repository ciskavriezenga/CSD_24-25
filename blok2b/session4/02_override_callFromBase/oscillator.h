#pragma once

#include <iostream>

class Oscillator
{
public:
  Oscillator();
  ~Oscillator();

  void tick();
  void calculate();
};
