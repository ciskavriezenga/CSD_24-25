#include "synth.h"

Synth::Synth()
{
  std::cout << "\n• Synth::Synth" << std::endl;
}

Synth::~Synth()
{
  std::cout << "\n• Synth::~Synth" << std::endl;
}


void Synth::setWaveform(Waveform type)
{
  std::cout << "\n• Synth::setWaveform" << std::endl;

  std::cout << "\n - using " << waveformTypeToString(type) << " as waveform"
            << std::endl;
  switch (type) {
    case Waveform::Sine:
      // set sine
      std::cout << "\n--- selecting sine";
      break;
    case Waveform::Saw:
      // set saw
      std::cout << "\n--- selecting saw";
      break;
    case Waveform::Square:
      // set square
      std::cout << "\n--- selecting square";
      break;
    default:
      break;
  }
}


std::string Synth::waveformTypeToString(Waveform type)
{
  switch(type) {
    case Waveform::Sine:
      return "sine";
    case Waveform::Saw:
      return "saw";
    case Waveform::Square:
      return "square";
    default:
      return "Invalid waveform";
  }
}