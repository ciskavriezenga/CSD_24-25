#pragma once

#include <iostream>
#include "effect.h"

class Delay : public Effect
{
public:
  // TODO - parameters
  Delay(int numDelaySamples, int maxDelaySamples);
  virtual ~Delay();

  void prepare(float samplerate) override {};

  void applyEffect(const float& input, float& output) override;

private:
  // hide default constructor
  Delay(){}
  void setDistanceRW(uint distanceRW);
  // increase write and read heads ands wrap if necessary
  inline void incrWriteH() {
    writeH++;
    wrapH(writeH);
  }

  inline void incrReadH() {
    readH++;
    wrapH(readH);
  }

  // wrap a head if necessary
  inline void wrapH(uint& head) {
    if (head >= size) head -= size;
  }

  // allocate and release methods, used to alter the buffer size
  void allocateBuffer();
  void releaseBuffer();

  // pointer to the buffer
  float* buffer;
  // buffer size
  uint size;
  // read and write heads, delay size
  uint readH {0};
  uint writeH {0};
  uint distanceRW;
};
