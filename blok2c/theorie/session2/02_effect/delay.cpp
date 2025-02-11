#include "delay.h"
#include <iostream>

Delay::Delay(float feedback, uint numDelaySamples,
  uint maxDelaySize, float dryWet) : Effect(dryWet),
  m_feedback(0), m_numDelaySamples(0),
  m_size(maxDelaySize), m_readH(0), m_writeH(0)
{
  // validate delay size and numDelaySamples
  if(numDelaySamples > maxDelaySize) {
    throw "Delay::Delay - numDelaySamples exceeds maxDelaySize";
  }
  setFeedback(feedback);
  setNumDelaySamples(numDelaySamples);
  // allocate buffer and set all samples to 0

  m_buffer = (float*)malloc(maxDelaySize * sizeof(float));
  memset(m_buffer, 0, m_size * sizeof(float));
}

Delay::~Delay()
{
  // free data allocated with memset
  free(m_buffer);
}


// override base class method
// applies delay effect to the input frame and stores it to the output frame
void Delay::applyEffect(const float &input, float &output)
{
  // read value from circular buffer and increment readH
  output = m_buffer[m_readH++];
  wrapH(m_readH);
  // write value to circular buffer
  m_buffer[m_writeH++] = output * m_feedback + input;
  wrapH(m_writeH);
}

// sets the number of samples to delay
void Delay::setNumDelaySamples(uint numDelaySamples)
{
  // store new distance between R & W heads and update rhead position
	m_numDelaySamples = numDelaySamples;
  m_readH = m_writeH - numDelaySamples + m_size;
  wrapH(m_readH);
}

// sets the feedback value, should be in range [0, 1]
void Delay::setFeedback(float feedback)
{
  if(feedback < 0 || feedback > 1) {
    throw "Delay::setFeedback - feedback exceeds range [0, 1]";
  }
  m_feedback = feedback;
}
