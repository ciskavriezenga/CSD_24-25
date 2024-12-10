#pragma once

#include <iostream>

#define NUM_NOTES 10

class Melody
{
public:
  Melody();
  ~Melody();

  // setters and getters
  float getNote();

protected:
  // Cmaj7 -  arpeggio
  float melody[NUM_NOTES] = {60, 64, 67, 71, 64, 67, 64, 69, 60, 55};
  // the index of the current note - readIndex
  int index;
};
