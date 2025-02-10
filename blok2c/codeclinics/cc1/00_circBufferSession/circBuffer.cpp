#include "circBuffer.h"


CircBuffer::CircBuffer(int size, int numSamplesDelay)
  : readHead(0), writeHead(numSamplesDelay)
{
  // TODO - init dynamic buffer
}

CircBuffer::~CircBuffer()
{
  // TODO - release the dynamic allocated array
}

float CircBuffer::read() {
  return buffer[readHead];
}

void CircBuffer::write(float input) {
  buffer[writeHead] = input;
}

void CircBuffer::tick() {
  incrementHead(readHead);
  incrementHead(writeHead);
}

void CircBuffer::incrementHead(int& head) {
  head++;
  if(head >= SIZE_ARRAY) {
    head -= SIZE_ARRAY;
  }
}

