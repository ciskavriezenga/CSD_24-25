#include <iostream>
#include <audioToFile.h>

#define BUFFER_SIZE 10

int main() {
  // -----  create and buffer with 10 values; 10, 11, ..., 19 -----
  float buffer[BUFFER_SIZE];
  int offset = 10.0f;
  for(int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] = offset + i;
  }


  // ----- apply linear interpolation and write result to file -----
  // floating point index and incrementation value
  float fpIndex = 0;
  float incrValue = 1.5;
  // open file to write output to
  const std::string sourcePath = SOURCE_DIR;
  WriteToFile writeToFile (sourcePath + "/output.csv", true);

  // iterate through buffer with floating point index
  while (fpIndex < (BUFFER_SIZE - 1)) {
    // transform floating point index to integer index
    int i = (int) fpIndex;
    // retrieve restvalue floating point index (value after comma)
    float restValue = fpIndex - i;
    float low = buffer[i];
    float high = buffer[i + 1];
    float delta = high - low;
    float value = (restValue * delta) + low;
    std::cout << "\n-------------------------------"
      << "\ni: " << i
      << ", restValue: " << restValue
      << "\nlow: " << low
      << ", high: " << high
      << ", delta: " << delta
      << "\nvalue: " << value << std::endl;
    writeToFile.write(std::to_string(value) + "\n");
    // increment index
    fpIndex += incrValue;
  }


}
