#include <iostream>
#include <thread>
#include <audioToFile.h>
#include <square.h>
#include "circBuffer.h"

#define SAMPLERATE 44100

int main(int argc,char **argv)
{
  // with a 44100 samplerate and 882 frequency --> 50 samples for one cycle
  float freq = 882;
  // set delay to approximately a quarter cycle
  CircBuffer circBuffer(200, 12);

  circBuffer.logAllSettings();

  Square square(freq, SAMPLERATE);

  const std::string sourcePath = SOURCE_DIR;
  WriteToFile fileWdriter(sourcePath + "/output.csv", true);

  // generate 200 samples
  // write sum of output of both the square directly and the circBuffer to a file
  float squareSample = 0;
  for(int i = 0; i < 200; i++) {
    squareSample = square.genNextSample();
    circBuffer.write(squareSample);
    std::cout << circBuffer.read();
    fileWriter.write(std::to_string(squareSample + circBuffer.read()) + "\n");
    circBuffer.tick();
  }

  std::cout << "\n***** DONE ***** "
    << "\nWrote the sum of the a sine oscillator and a "
    << "delayed value to output.csv." << std::endl;

  //end the program
  return 0;

} // main()
