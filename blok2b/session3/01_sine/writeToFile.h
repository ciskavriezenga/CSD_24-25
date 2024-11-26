#include <iostream>
#include <fstream>
#include <sys/stat.h>


class WriteToFile
{
public:
  WriteToFile(std::string fileName, bool overwrite=false);
  ~WriteToFile();

  bool write(std::string text);

private:
  bool fileExists(const std::string& fileName);
  bool openFile(std::string fileName);
  std::ofstream file;
};
