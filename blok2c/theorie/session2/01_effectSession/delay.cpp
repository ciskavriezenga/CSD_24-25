#include "delay.h"

Delay::Delay(int numDelaySamples, int maxDelaySamples) :
size(maxDelaySamples) {
  allocateBuffer();
  setDistanceRW(numDelaySamples);
}

Delay::~Delay() {

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
  buffer = (float*)malloc(size * sizeof(float));
  memset(buffer, 0, size * sizeof(float));
}

void Delay::releaseBuffer()
{
  // free data allocated with memset
  free(buffer);
}

void Delay::setDistanceRW(uint distanceRW)
{
  // store new distance between R & W heads and update rhead position
  distanceRW = distanceRW;
  readH = writeH - distanceRW + size;
  wrapH(readH);
}


