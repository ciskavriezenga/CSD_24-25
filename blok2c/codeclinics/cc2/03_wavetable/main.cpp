#include <iostream>
#include "wavetableGenerator.h"
#include <audioToFile.h>

#define BUFFER_SIZE 512

int main() {
  // generate wavetable and fill with sine waveform
  float wavetable[BUFFER_SIZE];
  WavetableGenerator::generateWaveform(wavetable, BUFFER_SIZE,
    WavetableGenerator::WaveformType::SINE);

  // write generated wavetable to csv file
  const std::string sourcePath = SOURCE_DIR;
  WriteToFile writeToFile (sourcePath + "/output.csv", true);

  for(int i = 0; i < BUFFER_SIZE; i++) {
    writeToFile.write(std::to_string(wavetable[i]) + "\n");
  }

  std::cout << "\n***** DONE ***** "
    << "\nOutput is written to file output.csv" << std::endl;
}
