#pragma once
#include "effect.h"
#define BUFFER_SIZE 44100

class Delay : public Effect {
public:
  Delay(int delaySamples, int maxDelaySamples,
        float feedback = 0.0f, float dryWet = 1.0f);
  ~Delay();

  // setters & getters
  void setFeedback(float feedback);
private:
  float applyEffect(float sample) override;

  void wrapH(int& head);


  // hide default constructor
  Delay() {};
  float feedback;

  // static buffer for the sake of simplicity (#example)
  float buffer[BUFFER_SIZE];
  int readH;
  int writeH;
};


