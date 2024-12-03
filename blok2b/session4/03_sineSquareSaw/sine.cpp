#include "sine.h"

Sine::Sine (float frequency, float samplerate)
  : Oscillator (frequency, samplerate) {
  std::cout << "• Sine::Sine - constructor\n";
}

Sine::~Sine() { std::cout << "• Sine::~Sine\n"; }

void Sine::calculate() {
  sample = sin (M_PI * 2 * phase);
}
