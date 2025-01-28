#pragma once

#include <iostream>
#include "oscillator.h"

class Tremolo
{
public:
  enum WaveformType {
    SINE = 0, // ensure enum starts at 0
    SAW,
    SQUARE,
    SIZE // 3
  };
  Tremolo(float modFreq = 10.0f, float modDepth = 1.0f,
    WaveformType waveformType = WaveformType::SINE, float samplerate = 44100);
  ~Tremolo();

  void prepare(float samplerate);

  // applies tremolo effect to the values from inbuf, stores results in outbuf
  void process(float const* inBuf, float* outbuf, int numFrames);

  // set the frequency of the tremolo
  void setModFreq(float modFreq);



protected:
  Oscillator* osc;
  // default modulation frequency range values
  // NOTE: no setters yet
  float modFreqMin = 0.01f;
  float modFreqMax = 50.0f;
  // modulation depth value
  // NOTE: no validation yet
  float modDepth;
};
