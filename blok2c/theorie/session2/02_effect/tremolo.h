#pragma once

#include "effect.h"
#include "oscillator.h"

class Tremolo : public Effect
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

  void prepare(float samplerate) override;
  // override base class method
  // applies tremolo effect to the input frame
  void applyEffect(const float &input, float &output) override;


  // set the frequency of the tremolo
  void setModFreq(float modFreq);

protected:
  Oscillator* m_osc;

  // default modulation frequency range values
  // NOTE: no setters yet
  float m_modFreqMin = 0.01f;
  float m_modFreqMax = 50.0f;
  // modulation depth value
  // NOTE: no validation yet
  float m_modDepth;

  // modSignal is used during the calculation of the processed frame
  float m_modSignal = 0;
};
