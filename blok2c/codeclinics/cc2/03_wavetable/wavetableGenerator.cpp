#include "wavetableGenerator.h"

void WavetableGenerator::generateWaveform(float* buffer, int numFrames,
  WaveformType waveformType) {
  Oscillator* osc;
  float freq = 1.0;
  switch(waveformType) {
    case WaveformType::SINE:
    {
      osc = new Sine(freq, numFrames);
      break;
    }
    case WaveformType::SAW:
    {
      osc = new Saw(freq, numFrames);
      break;
    }
    case WaveformType::SQUARE:
    {
      // TODO: alter calculation of to create a non-aliasing square,
      // similar to the calculation within the Saw class
      osc = new Square(freq, numFrames);
      break;
    }
    default:
      throw "WavetableGenerator::WavetableGenerator - incorrect waveformType.";
      break;
  }

  for(int i = 0; i < numFrames; i++) {
    buffer[i] = osc->genNextSample();
  }
  // release dynamically allocated oscillator object
  delete osc;
  osc = nullptr;
}
