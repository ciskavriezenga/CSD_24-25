#pragma once

class Effect
{
public:
  // drywet: drywet balance
  // drywet == 0:     dry
  // 0 < drywet < 1:  mix
  // drywet == 1:     wet
  // default is wet
  Effect(float dryWet = 1.0);
  virtual ~Effect();

  virtual void prepare(float samplerate) = 0;
  void processFrame(const float& input, float& output);

protected:
  virtual void applyEffect(const float& input, float& output) = 0;
private:

};
