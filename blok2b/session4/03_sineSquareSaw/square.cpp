#include "square.h"

Square::Square (float frequency, float samplerate)
  : Oscillator (frequency, samplerate) {
  std::cout << "• Square::Square - constructor\n";
}

Square::~Square() { std::cout << "• Square::~Square\n"; }

void Square::calculate() {
  if(phase < 0.5f) {
    sample = 1.0f;
  } else {
    sample = -1.0f;
  }
}
