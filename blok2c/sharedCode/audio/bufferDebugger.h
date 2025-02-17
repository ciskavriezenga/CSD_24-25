#pragma once
#include <iostream>


// static utility class with debug functionality for buffers
class BufferDebugger
{
public:
  // logs first n values in the buffer to the console
  static void logBegin(float* buffer, uint bufSize, uint nFrames);
  // logs last n values in the buffer to the console
  static void logEnd(float* buffer, uint bufSize, uint nFrames);
  // logs values in the buffer in a given range to the console
  // endIndex is exclusive
  static void logRange(float* buffer, uint bufSize, uint startIndex,
    uint endIndex);

  // writes values in the buffer to file
  static void writeToFile(float* buffer, int bufSize, std::string filePath);
  // writes values in the buffer in given range to file
  // endIndex is exclusive
  static void writeToFileRange(float* buffer, int bufSize, int startIndex,
    int endIndex, std::string filePath);

private:
  // hide default constructor
  BufferDebugger() {};
};
