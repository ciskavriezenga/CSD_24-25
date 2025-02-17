#include <iostream>
#include <thread>
#include <audioToFile.h>
#include <square.h>
#include "circBuffer.h"


#define SAMPLERATE 44100

int main(int argc,char **argv)
{
  // set delay to a quarter cycle
  int cycleFrameLength = 80;
  CircBuffer circBuffer(200, cycleFrameLength / 4);

  // init square oscillator based on cycle lengths
  float freq = (float) SAMPLERATE / cycleFrameLength;
  Square square(freq, SAMPLERATE);

  const std::string sourcePath = SOURCE_DIR;
  WriteToFile fileWriter(sourcePath + "/output.csv", true);

  // generate 200 samples
  // TODO - write sum of output of both the square directly and the circBuffer to a file
  float squareSample = 0;
  for(int i = 0; i < 200; i++) {
    squareSample = square.genNextSample();
    fileWriter.write(std::to_string(squareSample) + "\n");
    // TODO - 'plugin' the cicbuffer

  }

  std::cout << "\n***** DONE ***** "
    << "\nWrote the sum of the a sine oscillator and a "
    << "delayed value to output.csv." << std::endl;

  //end the program
  return 0;

} // main()
