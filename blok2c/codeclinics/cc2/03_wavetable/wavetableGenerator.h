#pragma once
#include <iostream>
#include <sine.h>
#include <saw.h>
#include <square.h>

class WavetableGenerator
{
public:
  enum WaveformType {
    SINE = 0, // ensure enum starts at 0
    SAW,
    SQUARE,
    SIZE // 4
  };
  static void generateWaveform(float* buffer, int numFrames,
    WaveformType waveformType);

private:
  // hide default constructor
  WavetableGenerator() {};
};
