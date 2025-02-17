#pragma once

#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator
{
public:
  Saw() {std::cout << "Saw::Saw -- constructor \n";}
  ~Saw() {std::cout << "Saw::~Saw -- destructor \n";}

  //override calculate from base class
  void calculate() {std::cout << "Saw::calculate\n";}
};
