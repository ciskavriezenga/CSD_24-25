#pragma once

#include <iostream>
#define SIZE_ARRAY 512

class CircBuffer {
public:
  CircBuffer(int size, int numSamplesDelay);
  ~CircBuffer();
  float read();
  void write(float input);
  // go to the next read and write position
  void tick();

private:
  void incrementHead(int& head);
  // TODO - use a dynamic buffer instead, and use size from constructor
  float buffer[SIZE_ARRAY];
  int readHead;
  int writeHead;
};


