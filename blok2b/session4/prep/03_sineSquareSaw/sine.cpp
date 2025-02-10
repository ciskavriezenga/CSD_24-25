#include "sine.h"
#include "math.h"

Sine::Sine (float frequency, float samplerate)
  : Oscillator (frequency, samplerate) {
  std::cout << "• Sine::Sine - constructor\n";
}

Sine::~Sine() { std::cout << "• Sine::~Sine\n"; }

void Sine::calculate() {


}
