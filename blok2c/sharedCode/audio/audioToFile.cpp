#include "audioToFile.h"

WriteToFile::WriteToFile (std::string fileName, bool overwrite) {
  // check if we are allowed to overwrite file
  if (! overwrite) {
    if (fileExists (fileName)) {
      std::cout << "\n------WriteToFile::WriteToFile------"
                << "File already exists, not allowed to overwrite!\n";
      // NOTE: for now, simple solution: EXIT
      throw "WriteToFile::WriteToFile - not able to open file: it already exists and not allowed to overwrite it.";
    }
  }
  openFile (fileName);
}

WriteToFile::~WriteToFile() { file.close(); }

bool WriteToFile::write (const std::string& text) {
  if (file.is_open()) {
    file << text;
    return true;
  } else
    return false;
}

bool WriteToFile::fileExists (const std::string& fileName) {
  // create a variable of type "struct stat"
  struct stat buffer;
  //check if file exists
  if (stat (fileName.c_str(), &buffer) != -1) {
    return true;
  }
  return false;
}

bool WriteToFile::openFile (const std::string& fileName) {
  file.open (fileName);
  return file.is_open();
}


AudioToFile::AudioToFile (const std::string& fileName,
                          int numInputchannels,
                          int numOutputChannels,
                          int numFrames)
  : numInputChannels (numInputchannels),
    numOutputChannels (numOutputChannels),
    numFrames(numFrames) {
  // instantiate fileWriter and AudioBuffer

  fileWriter = std::make_unique<WriteToFile>(fileName, true);

  inputChannel = new float*[numInputChannels];
  outputChannel = new float*[numOutputChannels];

  for (int i = 0; i < numInputChannels; i++) {
    inputChannel[i] = new float[numFrames];
  }
  for (int i = 0; i < numOutputChannels; i++) {
    outputChannel[i] = new float[numFrames];
  }
}

AudioToFile::~AudioToFile() {
  // delete all buffers
  for (int i = 0; i < numInputChannels; i++) {
    delete[] inputChannel[i];
    inputChannel[i] = nullptr;
  }
  for (int i = 0; i < numOutputChannels; i++) {
    delete[] outputChannel[i];
    outputChannel[i] = nullptr;
  }
  delete[] inputChannel;
  delete[] outputChannel;
}

void AudioToFile::write(AudioCallback& callback) {
  // TODO - CODE REVIEW
  // CODE BELOW IS HASTLY CODED ...

  AudioBuffer audioBuffer =
    AudioBuffer { .inputChannels = const_cast<const float**> (inputChannel),
                  .outputChannels = outputChannel,
                  .numInputChannels = numInputChannels,
                  .numOutputChannels = numOutputChannels,
                  .numFrames = numFrames };

  callback.process (audioBuffer);
  for (int i = 0; i < numFrames; i++) {
    fileWriter->write (std::to_string (audioBuffer.outputChannels[0][i])
                       + "\n");
  }
}