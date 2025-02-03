#include "delay.h"


Delay::Delay(int delaySamples, int maxDelaySamples,
        float feedback, float dryWet) : Effect(dryWet),
        writeH(0), readH(BUFFER_SIZE - delaySamples) {
  // TODO validate:
  //    delaySamples <= maxDelaySamples
  //    > 0 etc.
}

Delay::~Delay() {}

float Delay::applyEffect(float sample) {
  float output = buffer[readH++];
  wrapH(readH);

  buffer[writeH++]= sample;
  wrapH(writeH);

  // TODO implement feedback functionality
  return output;
}

void Delay::wrapH(int &head) {
  if(head >= BUFFER_SIZE) {
    head -= BUFFER_SIZE;
  }
}

void Delay::setFeedback(float feedback)
{
  // validate value
  if(feedback >=0.0f && feedback <= 0.99f) {
    this->feedback = feedback;
  } else {
    // TODO - log error
  }

}

