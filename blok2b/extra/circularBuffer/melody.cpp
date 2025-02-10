#include <iostream>
#include "melody.h"

// constructor and destructor
Melody::Melody()
{
    readIndex = 0;
    writeIndex = 0;
    // initialize the notes array with -1, representing empty spots
    for(int i = 0; i < NUM_NOTES; i++) {
      notes[i] = -1;
    }
}

Melody::~Melody() {}

int Melody::getNote()
{

  // check if melody is empty
  std::cout << "\n writeIndex: " << writeIndex << " readIndex: " << readIndex << std::endl;
  if(readIndex == writeIndex) { //empty
    std::cout << "Melody is empty" << std::endl;
    return -1;
  }
  // return current note and then increase readIndex
  // readIndex++ --> first use the value, then increment value
  // ++readIndex --> first increment value, then use the value
  int note = notes[readIndex++];
  // wrap readIndex
  if(readIndex >= NUM_NOTES) readIndex -= NUM_NOTES;
  return note;
}


void Melody::addNote(int note)
{
  // check if circular buffer is full or not
  if((writeIndex + 1)%NUM_NOTES == readIndex) { // full
    std::cout << "\nMelody::addNote - "
      << "Melody is full, not possible to add a note!" << std::endl;
  } else { // not full
    // check if note is not a negative value
    if(note >= 0) {
      // add note and increase writeIndex
      notes[writeIndex++] = note;
    } else { // negative value
      std::cout << "\nMelody::addNote - "
        << "does not accept negative notes!" << std::endl;
    }
  }
  // wrap writeIndex
  if(writeIndex >= NUM_NOTES) writeIndex -= NUM_NOTES;
}
