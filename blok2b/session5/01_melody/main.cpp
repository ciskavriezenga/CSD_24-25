/*
  Example program that plays a simple hard coded 01_melody using a square wave oscillator
*/

#include "callback.h"
#include <iostream>

int main (int argc, char** argv) {
  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  Callback audioSource (44100.0f);

  JUCEModule juceModule (audioSource);
  juceModule.init (1, 1);

  std::cout << "\n\nType 'q + enter' to exit\n";
  bool running = true;
  while (running) {
    switch (std::cin.get()) {
      case 'q':
        running = false;
        break;
    }
  }

  return 0;

}
