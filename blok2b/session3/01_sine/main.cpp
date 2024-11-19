#include <iostream>
#include "sine.h"
#include "writeToFile.h"


int main() {
  // create sine wave
  Sine sine(220);
  std::cout << "Sine frequency: " << sine.getFrequency() << "\n";

  // write 1 second of samples to file
  // second parameter - overwrite is set to true
  WriteToFile fileWriter("output.csv", true);
  for(int i = 0; i < SAMPLERATE; i++) {
    fileWriter.write(std::to_string(sine.getSample()) + "\n");
    sine.tick();
  }

  // end of program
  return 0;
}
