/*
  Example program that plays a simple hard coded 01_melody using a square wave oscillator
*/

#include "audiocomponent.h"
#include "cmath"
#include "melody.h"
#include "square.h"
#include <iostream>
#include <thread>


class Callback : public AudioCallback {
public:
  Callback (float sampleRate)
    : AudioCallback (sampleRate), sampleRate (sampleRate) {
    std::cout << "Hallo Ciska" << std::endl;
  }

  double mtof (float mPitch) {
    return 440.0 * pow (2.0, (mPitch - 69.0f) / 12.0f);
  }


  void updatePitch (Melody& melody, Square& square) {
    float note = melody.getNote();
    double freq = mtof (note);
    std::cout << "next note: " << note << ", has frequency " << freq
              << std::endl;
    square.setFrequency (freq);
  }


  void prepare (int sampleRate) override {
    this->sampleRate = sampleRate;
    updatePitch (melody, square);
  }


  void process (AudioBuffer buffer) override {
    auto [inputChannels,
          outputChannels,
          numInputChannels,
          numOutputChannels,
          numFrames] = buffer;

    for (int channel = 0; channel < numOutputChannels; ++channel) {
      for (int sample = 0; sample < numFrames; ++sample) {
        outputChannels[channel][sample] = square.getSample() * amplitude;
        square.tick();

        /* After every sample, check if we need to advance to the next note
	     * This is a bit awkward in this scheme of buffers per channel
	     *  In a multichannel setting we should update pitches independently per channel!
	     */
        if (frameIndex >= noteDelayFactor * sampleRate) {
          // reset frameIndex
          frameIndex = 0;
          updatePitch (melody, square);
        } else {
          // increment frameindex
          frameIndex++;
        }
      }  // for sample
    }  // for channel
  }  // process()

private:
  double sampleRate;
  Square square;
  double amplitude = 0.25;
  Melody melody;
  int frameIndex = 0;

  /* instead of using bpm and specifying note lenghts we'll make every note
   * equal length and specify the delay between notes in terms of the samplerate
   *
   * A note of say 500 msec or 0.5 sec, takes 0.5*samplerate samples to be played
   */
  double noteDelayFactor = 0.1;
};  // Callback{}


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
  }  // while

  return 0;

}  // main()
