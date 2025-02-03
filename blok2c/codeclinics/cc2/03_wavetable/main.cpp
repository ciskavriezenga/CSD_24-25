#include <iostream>
#include "wavetableGenerator.h"
#include "writeToFile.h"

#define BUFFER_SIZE 512

int main() {
  // generate wavetable and fill with sine waveform
  float wavetable[BUFFER_SIZE];
  WavetableGenerator::generateWaveform(wavetable, BUFFER_SIZE,
    WavetableGenerator::WaveformType::SINE);

  // write generated wavetable to csv file
  WriteToFile fileWriter("output.csv", true);
  for(int i = 0; i < BUFFER_SIZE; i++) {
    fileWriter.write(std::to_string(wavetable[i]) + "\n");
  }

  std::cout << "\n***** DONE ***** "
    << "\nOutput is written to file output.csv" << std::endl;
}
