//
// Created by Ciska Vriezenga on 06/12/2022.
//

#include "sine.h"
#include "math.h"

Sine::Sine (float frequency, float samplerate)
  : Oscillator (frequency, samplerate) {
  std::cout << "Sine::Sine constructor\n";
}

void Sine::calculate() { sample = sin (M_PI * 2 * phase) * amplitude; }