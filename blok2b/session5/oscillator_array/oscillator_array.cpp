#include <iostream>

class Oscillator
{
public:
  virtual void calculate() { std::cout << "Oscillator calculate()" <<
    " is somewhat useless because we don't know the waveform" << std::endl; }
};


class Sine : public Oscillator
{
public:
  void calculate() { std::cout << "Sine calculate()" << std::endl; }
};


class Square : public Oscillator
{
public:
  void calculate() { std::cout << "Square calculate()" << std::endl; }
};


class Saw : public Oscillator
{
public:
  void calculate() { std::cout << "Saw calculate()" << std::endl; }
};


int main()
{

  // create a bank of Oscillators as an array of Oscillator pointers
  // In this step the array contains no useful values because the objects
  // and their pointers have not yet been created
  Oscillator* oscillatorBank[5];

  // fill every place in the array with a pointer to a new object
  oscillatorBank[0] = new Oscillator;
  oscillatorBank[1] = new Sine;
  oscillatorBank[2] = new Square;
  oscillatorBank[3] = new Sine;
  oscillatorBank[4] = new Saw;

  // let every Oscillator report what type it actually is
  for(int i=0; i<5; i++){
    oscillatorBank[i]->calculate();
  }

}

