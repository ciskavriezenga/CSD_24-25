#include <iostream>
#include <thread>
#include "jack_module.h"
#include "writeToFile.h"
#include "math.h"
#include <limits>

#define BUFFER_SIZE 50
int main(int argc,char **argv)
{
  /*
  Starting with phase 0 --> no problem occure. We create a correct waveform.
  Starting at phase 8200 --> something 'strange' happens ;)
  Question: What is going wrong?
  */
  float phase = 0; // 8200
  // frequency of 882 --> exactly 50 samples for 1 period with 44100 samplerate
  float frequency = 882;
  float samplerate = 44100;

  // write 1 period of the waveform to a file and a buffer
  WriteToFile fileWriter("output.csv", true);
  float buffer[BUFFER_SIZE];
  for(int i = 0; i < BUFFER_SIZE; i++) {
    // starting at phase 8200 --> 8200 * 2.0 * 3.14159 = 51,522.076
    float sample = sin(phase * M_PI * 2.0f );
    fileWriter.write(std::to_string(sample) + "\n");
    phase += frequency / samplerate;
    buffer[i] = sample;
  }

#if 0
  std::cout << "\n" << M_PI << "\n";
  std::cout << "\nwith floats: " << sin(phase + (1.0f / 882.0f * 881.0f) * M_PI * 2.0f ) << "\n";
  std::cout << "\nwith doubles: " << sin(phase + (1.0 / 882.0 * 881.0) * M_PI * 2.0 ) << "\n";
  float sample = sin(phase + (1.0f / 882.0f * 881.0f) * M_PI * 2.0f );
  std::cout << "\n" << sample << "\n";
#endif

  // Now we are going to use the buffer with one waveform as source in the
  // jack audio callback function, so we can listen to its content.

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  // keep track of the current read position with a read head
  int readH = 0;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&readH, buffer](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = buffer[readH];
      readH++;
      if(readH >= BUFFER_SIZE) readH -= BUFFER_SIZE;
    }
    return 0;
  };


  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }

  // end of program
  return 0;
}
