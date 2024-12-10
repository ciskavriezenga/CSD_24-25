#pragma once

#include <iostream>




class Synth
{
public:
  Synth();
  ~Synth();

  // NOTE: needs to be same order as the waveFormOptions string array
  enum Waveform {
    Sine = 0, // ensure enum starts at 0
    Saw,
    Square,
    Size // 3
  };
  // setters and getters
  void setWaveform(Waveform type);

  // static method because this method does not depend on objects
  static std::string waveformTypeToString(Waveform type);

protected:

};