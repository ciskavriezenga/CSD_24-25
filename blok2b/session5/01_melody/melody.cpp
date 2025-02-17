#include "melody.h"

Melody::Melody()
{}

Melody::~Melody()
{}


/*
 * getNote() reads the next note from the 01_melody
 *  and wraps around to the beginning when it reached the end
 *  of the 01_melody
 */
float Melody::getNote()
{
  // wrap index back to the beginning
  if(index >= NUM_NOTES) {
    index = 0;
  }
  // index++ --> use value, then increment
  return melody[index++];
}
