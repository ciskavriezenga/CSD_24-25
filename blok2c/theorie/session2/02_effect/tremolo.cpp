#include "tremolo.h"
#include "saw.h"
#include "sine.h"
#include "square.h"
#include <iostream>

Tremolo::Tremolo(float modFreq, float modDepth,
      WaveformType waveformType, float samplerate) : Effect(), m_modDepth(modDepth)
{
  // instantiate the oscillator, depending on the passed waveform type
  switch (waveformType) {
  case WaveformType::SINE:
  {
    m_osc = new Sine(modFreq, samplerate);
    break;
  }
  case WaveformType::SAW:
  {
    m_osc = new Saw(modFreq, samplerate);
    break;
  }
  case WaveformType::SQUARE:
  {
    // TODO: alter calculation of to create a non-aliasing square,
    // similar to the calculation within the Saw class
    m_osc = new Square(modFreq, samplerate);
    break;
  }
  default:
    throw "Tremelo::Tremelo - incorrect waveformType.";
    break;
  }
}

Tremolo::~Tremolo()
{
  // release dynamically allocated oscillator object.
  delete m_osc;
  m_osc = nullptr;
}

void Tremolo::prepare(float samplerate) {
  // NOTE: example, keeping things 'simple', hence no validation
  m_osc->prepare(samplerate);
}

void Tremolo::applyEffect(const float &input, float &output)
{
  // transform sine in range [-1, 1] to range [0, 1]
  m_modSignal  = m_osc->genNextSample() * 0.5 + 0.5;
  // apply modDepth
  m_modSignal *= m_modDepth;
  m_modSignal += 1.0 - m_modDepth;
  // apply modulation signal to input and return result
  output = input * m_modSignal;
}

void Tremolo::setModFreq(float modFreq)
{
  if(modFreq >= m_modFreqMin && modFreq <= m_modFreqMax) {
    m_osc->setFrequency(modFreq);
  } else {
    std::cout << "• Tremelo::setModFreq - modFreq is incorrect"
      << " please pass value between " << m_modFreqMin << " and " << m_modFreqMax
      << std::endl;
  }

}
