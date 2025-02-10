#include "oscillator.h"


Oscillator::Oscillator() {
  std::cout << "• Oscillator::Oscillator\n";
}

Oscillator::~Oscillator() {
  std::cout << "• Oscillator::~Oscillator\n";
}

void Oscillator::tick() {
  std::cout << "• Oscillator::tick\n";
  std::cout << "UPDATING THE PHASE\n";
  calculate();
}
