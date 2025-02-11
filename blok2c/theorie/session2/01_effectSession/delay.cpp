#include "delay.h"

#include <sine.h>

Delay::Delay(int numDelaySamples, int maxDelaySamples) :
size(maxDelaySamples) {
  allocateBuffer();
  setDistanceRW(numDelaySamples);
}

Delay::~Delay() {
  releaseBuffer();
}

void Delay::applyEffect(const float& input, float& output) {
  output = buffer[readH];
  incrReadH();
  // TODO - instead of 0.25 use a feedback variable
  buffer[writeH] = input + output * 0.25;
  incrWriteH();
}

void Delay::allocateBuffer()
{
  // allocate buffer and set all samples to 0
  buffer = new float[size];
  for (int i = 0; i < size; i++) {
    buffer[i] = 0;
  }
}

void Delay::releaseBuffer()
{
  // free data allocated with memset
  delete[] buffer;
  buffer = nullptr;
}

void Delay::setDistanceRW(uint distanceRW)
{
  // store new distance between R & W heads and update rhead position
  distanceRW = distanceRW;
  readH = writeH - distanceRW + size;
  wrapH(readH);
}


