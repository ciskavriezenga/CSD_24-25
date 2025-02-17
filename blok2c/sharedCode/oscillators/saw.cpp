#include "saw.h"
#include "math.h"

#define SAW_SMOOTH_FACTOR 5.0f

Saw::Saw() : Saw(0, 0) {}

Saw::Saw(float frequency, float samplerate) :
  Oscillator(frequency, samplerate),
  phaseIncrement(frequency / samplerate * SAW_SMOOTH_FACTOR),
  smoothY(0)
{
  std::cout << "Saw - constructor\n";
}


Saw::~Saw()
{
  std::cout << "Saw - destructor\n";
}

//override calculate method
//this method contains the sample calculation
void Saw::calcNextSample()
{
  //add 0.5 to phase, to allow a regular sawwave
  //(starting at 0, -> 1, -1 -> 0 )
  wPhase = phase + 0.5;
  //we want values between: [0.0, 1.0], so wrap it
  if(wPhase > 1) wPhase -= 1.0;

  //calculate the pure sawwave
  sample = wPhase * 2.0 - 1.0;

  //we want to apply smoothing to prevent aliasing
  //using Polynomial to smooth the corners of the sawwave
  //TODO - add comments to explain
  if(wPhase < phaseIncrement) {
    /*
    the first SAW_SMOOTH_FACTOR samples are below phaseIncrement
    next, we calcultate the smoothY value, between: [0,1]
      e.g. freq 50 --> 882 samples per period with samplerate 44100
      2nd sample, wPhase = 50 / 44100 = 0.001133786848
      with SAW_SMOOTH_FACTOR = 5
      phaseIncrement = 50 / 44100 * 5 = 0.00566893424
      smoothY = 0.001133786848 / 0.00566893424 = 0.2
      wPhase < phaseIncrement will hold true for the first 5 samples
      thus --> smoothY = 0, 0.2, 0.4, 0.6, 0.8
        smoothY_0 = 0 + 0 - 0 * 0 - 1.0 = -1
        smoothY_1 = 0.2 + 0.2 - 0.2 * 0.2 - 1.0 = -0.64
        smoothY_2 = 0.4 + 0.4 - 0.4 * 0.4 - 1.0 = -0.36
        smoothY_3 = 0.6 + 0.6 - 0.6 * 0.6 - 1.0 = -0.16
        smoothY_4 = 0.8 + 0.8 - 0.8 * 0.8 - 1.0 = -0.04
      next, sample - smoothY --> phase = 0 --> results in output 0
      in 5 steps it will 'smoothly' glide to -1
    */
    smoothY = wPhase / phaseIncrement;
    smoothY = smoothY + smoothY - smoothY * smoothY - 1.0;
  } else if (wPhase > 1.0 - phaseIncrement) {
    smoothY = (wPhase - 1.0) / phaseIncrement;
    smoothY = smoothY + smoothY + smoothY * smoothY + 1.0;
    /*
    Regarding the example above, freq 50, last 5 samples results in:
      smoothY_877 = 0.04
      smoothY_878 = 0.16
      smoothY_879 = 0.36
      smoothY_880 = 0.64
      smoothY_881 = 1
    next, sample - smoothY --> in 5 steps it will 'smoothly' glide from 1 to 0
  */
  } else {
    smoothY = 0;
  }
  sample -= smoothY;
}
