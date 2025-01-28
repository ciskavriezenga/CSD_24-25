#include "square.h"
#include "math.h"

Square::Square() : Square(0, 0) {}

Square::Square(float frequency, float samplerate) :
  Oscillator(frequency, samplerate)
{
  std::cout << "Square - constructor\n";
}

Square::~Square() {
  std::cout << "Square - destructor\n";
}

void Square::calcNextSample()
{
  // square functionality comes here
  if(phase < 0.5) {
    sample = 1.0;
  } else {
    sample = -1.0;
  }
}
