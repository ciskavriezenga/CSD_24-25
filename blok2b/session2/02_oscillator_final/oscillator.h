#include <iostream>

// 3 type access specifiers:
// public, protected, private

class Oscillator
{
public:
  Oscillator();
  Oscillator(float freq, float amp);
  ~Oscillator();

  // setters and getters
  void setFreq(float freq);
  float getFreq();

protected:
  float freq;
  float amp;
};
