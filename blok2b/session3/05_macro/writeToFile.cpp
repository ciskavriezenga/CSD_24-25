#include "writeToFile.h"

WriteToFile::WriteToFile(std::string fileName, bool overwrite)
{
  // check if we are allowed to overwrite file
  if(!overwrite) {
    if(fileExists(fileName)){
      std::cout << "\n------WriteToFile::WriteToFile------"
        << "File already exists, not allowed to overwrite!\n";
      // NOTE: for now, simple solution: EXIT
      throw "WriteToFile::WriteToFile - not able to open file: it already exists and not allowed to overwrite it.";
    }
  }
  openFile(fileName);
}

WriteToFile::~WriteToFile()
{
  file.close();
}

bool WriteToFile::write(std::string text)
{
  if(file.is_open())
  {
    file << text;
    return true;
  } else return false;
}

bool WriteToFile::fileExists(const std::string& fileName)
{
  // create a variable of type "struct stat"
  struct stat buffer;
  //check if file exists
  if (stat(fileName.c_str(), &buffer) != -1)
  {
    return true;
  }
  return false;
}

bool WriteToFile::openFile(std::string fileName)
{
  file.open(fileName);
  return file.is_open();
}
