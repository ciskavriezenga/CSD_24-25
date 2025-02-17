#pragma once

#include <iostream>

class Oscillator
{
public:
  Oscillator() {std::cout << "Oscillator::Oscillator -- constructor\n";}
  ~Oscillator() {std::cout << "Oscillator::~Oscillator -- destructor\n";}

  void calculate() { std::cout << "Oscillator::calculate\n";}
};
