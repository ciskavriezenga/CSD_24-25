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
    SIZE // 3
  };

  // generates a standard waveform in the range [-1, 1]
  static void generateWaveform(float* buffer, int bufSize,
    WaveformType waveformType);

  // generates an s-curve in the range [-1, 1], based arctangent function
  // k: influences the curve,
  //    k < 1, mimics linear function
  //    k = 1, nearly linear
  //    k > 1, more 'curvy'
  //    k > 100, "square-like"
  static void generateSCurve(float* buffer, int bufSize, float k);
  /*
   * NOTE: the functions below are placeholder functions!
   * TODO: please remove these and use your own map range function from your
   * Interpolation class within the wavetableGenerator.cpp file.
   */
   static float map(const float value, float fromLow, float fromHigh, float toLow,
    float toHigh);
   static float mapLin(float normValue, float low, float high);

private:
  // hide default constructor
  WavetableGenerator() {};


};
