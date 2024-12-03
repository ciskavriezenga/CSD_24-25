#pragma once

#include <iostream>

class Oscillator {
public:
  Oscillator();
  ~Oscillator();

  void tick();
  virtual void calculate() = 0;
};
