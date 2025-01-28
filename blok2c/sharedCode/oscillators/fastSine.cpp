#include "fastSine.h"
#include "math.h"

//Constructors and destructor
FastSine::FastSine(float frequency, float samplerate) :
  Oscillator(frequency, samplerate), tempPhase(0) {}

FastSine::~FastSine() {}

//override calculate method
//this method contains the sample calculation
void FastSine::calcNextSample()
{
  //translate phase to -PI..PI
  tempPhase = (phase - 0.5) * M_PI * 2;

  // calculate sine wave based on polynomial function
  if (tempPhase < 0)
    sample =  1.27323954 * tempPhase + .405284735 * tempPhase * tempPhase;
  else
    sample = 1.27323954 * tempPhase - 0.405284735 * tempPhase * tempPhase;
}
