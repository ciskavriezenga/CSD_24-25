#include <iostream>
#include <thread>
#include "math.h"
#include "audioToFile.h"
#include "oscillator.h"
#include "callback.h"
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define WRITE_TO_FILE 0


int main(int argc, char **argv) {
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    CustomCallback audioSource (44100);

#if WRITE_TO_FILE
  AudioToFile audioToFile;
  audioToFile.write(audioSource);
#else

    JUCEModule juceModule (audioSource);
    juceModule.init(1,1);

    std::cout << "Press q + Enter to quit..." << std::endl;
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

