#include <iostream>
#include "melody.h"



/*
Example with a very simple circular buffer, used to store a melody
(for sake of simplicity the melody contains integers)
*/


// read notes from melody till melody is empty
void readNotes(Melody melody) {
  int currentNote = melody.getNote();
  // display  the notes in the melody
  while(currentNote != -1) {
    // display current note
    std::cout << "\ncurrent note: " << currentNote << std::endl;
    // retrieve new note
    currentNote = melody.getNote();
  }
}

int main()
{
  /*
   * CASE 1
   * - read notes from melody till melody is empty
   */
  std::cout << "\n____ CASE 1 ____" << std::endl;
  // create melody instance
  Melody melody1;
  // generate and add some notes to melody
  for(int i = 0; i < 8; i++) {
    melody1.addNote(i);
  }
  // read notes from melody till melody is empty
  readNotes(melody1);


  /*
   * CASE 2
   * - add 10 notes --> full message,
   * - read 1
   * - add 1 --> should succeed
   * - read notes from melody till melody is empty
   */
  std::cout << "\n____ CASE 2 ____" << std::endl;
  // create melody instance
  Melody melody2;
  // generate and add some notes to melody
  for(int i = 0; i < 10; i++) {
    melody2.addNote(i);
  }
  // read 2 notes
  std::cout << "\ncurrent note: " << melody2.getNote() << std::endl;
  // // add another note
  melody2.addNote(9);
  // // read notes from melody till melody is empty
  readNotes(melody2);


  // TODO add CASE 3 --> add negative numbers, this should not be allowed


  // end program
  return 0;
}
