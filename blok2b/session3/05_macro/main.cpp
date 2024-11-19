#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"

#define AUDIO 1
#if 0
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override {
    samplerate = (float) rate;
    sine.setSamplerate(samplerate);
    std::cout << "\nsamplerate: " << samplerate << "\n";
  }

  void process(AudioBuffer buffer) override {
    for (int i = 0; i < buffer.numFrames; ++i) {
      // write sample to buffer at channel 0, amp = 0.25
      buffer.outputChannels[0][i] = sine.getSample();
      sine.tick();
    }
  }
  private:
  float samplerate = 44100;
  Sine sine = Sine(220, samplerate);
};
#endif
int main(int argc,char **argv)
{
  // TODO - add default Sine constructor and constructor delegation
  // TODO - initializer list
  // TODO - use a macro to switch between 'sounding sine' and 'write to file'


#if 0
  auto callback = CustomCallback {};
  auto jackModule = JackModule { callback };

  jackModule.init (0, 1);

  bool running = true;
  while (running) {
      switch (std::cin.get()) {
          case 'q':
              running = false;
      }
  }
#endif

  Sine sine;





  //end the program
  return 0;
} // main()
