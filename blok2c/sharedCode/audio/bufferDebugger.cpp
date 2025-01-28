#include "bufferDebugger.h"
#include "audioToFile.h"

// logs first n values in the buffer to the console
void BufferDebugger::logBegin(float* buffer, uint bufSize, uint nFrames)
{
  // validate nFrames
  if(nFrames > bufSize) {
    throw "BufferDebugger::logBegin - nFrames exceeds size of the buffer.";
  }
  logRange(buffer, bufSize, 0, nFrames);
}

// logs last n values in the buffer to the console
void BufferDebugger::logEnd(float* buffer, uint bufSize, uint nFrames)
{
  if(nFrames > bufSize) {
    throw "BufferDebugger::logEnd - nFrames exceeds size of the buffer.";
  }
  logRange(buffer, bufSize, bufSize - nFrames, bufSize);
}

// logs values in the buffer in a given range to the console
void BufferDebugger::logRange(float* buffer, uint bufSize, uint startIndex,
  uint endIndex)
{
  // validate range
  if(startIndex >= bufSize) {
    throw "BufferDebugger::logRange - startIndex exceeds size of the buffer.";
  }
  if(endIndex > bufSize) {
    throw "BufferDebugger::logRange - endIndex exceeds size of the buffer.";
  }
  // NOTE: endIndex is exclusive
  std::cout << "\n";
  if(startIndex <= endIndex) {
    for(int i = startIndex; i < endIndex; i++) {
      std::cout << buffer[i] <<  ", ";
    }
  } else {
    for(int i = endIndex; i >= startIndex; i--) {
      std::cout << buffer[i] <<  ", ";
    }
  }
  std::cout << std::endl;
}

// writes values in the buffer to file
void BufferDebugger::writeToFile(float* buffer, int bufSize,
  std::string filePath)
{
  writeToFileRange(buffer, bufSize, 0, bufSize, filePath);
}

// writes values in the buffer in given range to file
void BufferDebugger::writeToFileRange(float* buffer, int bufSize, int startIndex,
  int endIndex, std::string filePath)
{
  // write generated wavetable to csv file
  // endIndex is exclusive
  WriteToFile fileWriter(filePath, true);
  for(int i = startIndex; i < endIndex; i++) {
    fileWriter.write(std::to_string(buffer[i]) + "\n");
  }
}
