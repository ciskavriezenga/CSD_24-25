#include <iostream>

/*
 * class
 * 1. define the class
 * 2. define the constructor
 * 3. implement the constructor
 * 4. add fields / methods (and define the methods)
 */



class Note {
public:
  // default constructor
  Note(); // same name as class name

  // methods (a method is a function & a member of a class)
  // NOTE: for the sake of the example,
  //  play should probably not be part of the Note class
  // void --> no return
  void play();
  // int --> returns an integer
  int getVelocity();
  // fields (a field is a member of a class)
  int midiNoteValue;
  int velocity;
};

Note::Note() {
  std::cout << "Note - constructor\n";
  midiNoteValue = 0;
  velocity = 0;
}

void Note::play() {
  std::cout << "PLAYING NOTE: " << midiNoteValue
    << " at velocity: " << velocity << std::endl;
}

int Note::getVelocity() {
  return velocity;
}

int main() {
  Note aNote;

  aNote.midiNoteValue = 60;
  aNote.velocity = 127;
  aNote.play();
}

