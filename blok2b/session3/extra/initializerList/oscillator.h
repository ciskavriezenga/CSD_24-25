#ifndef OSCILLATOR_H
#define OSCILLATOR_H

class Oscillator {
public:
  Oscillator();
  Oscillator(float frequency, float amp);
  ~Oscillator();
  void setFrequency(float freq);
  float getFrequency();
  void setAmp(float amp);
  float getAmp();

  void displayCount();

private:
  float freq;
  float amp;
  static int count;
};
#endif
