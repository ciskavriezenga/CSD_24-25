#include <iostream>
#include <thread>
#include <audiocomponent.h>
#include <cmath>
#include "callback.h"
#include <audioToFile.h>


#define WRITE_TO_FILE 0


int main(int argc, char **argv) {
  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource{44100};

#if WRITE_TO_FILE
  AudioToFile audioToFile;
  audioToFile.write (audioSource);
#else

  JUCEModule juceModule (audioSource);
  juceModule.init (1, 1);

  bool running = true;
  while (running) {
    switch (std::cin.get()) {
      case 'q':
        running = false;
    }
  }
#endif
  //end the program
  return 0;
} // main()

