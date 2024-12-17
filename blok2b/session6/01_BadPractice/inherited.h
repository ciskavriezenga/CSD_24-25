//
// Created by Dean on 16/12/2024.
//

class Synth {
public:

  Synth();
  ~Synth();

  float getSample();
  void tick();
  virtual void calculate() = 0;

protected:
  Oscillator* oscillators;
  float sampleRate;
  float sample;
};

class Voice : Synth {
public:

  float getSample();
  void tick();

  void setFrequency(float frequency);
  void calculate() override;

private:
  Sine* sines;
  float currentFrequency;

};

class RingModulationSynth : Voice {
public:
  float getSample();
  void tick();

  void setPitch(int pitch);
  float mtof(int pitch);
  void calculate() override;

  void setFrequency(float frequency);
private:
  int pitch {34}; // midi pitch
};

class FrequencyModulationSynth : Synth {
public:

  void calculate() override;

  void setCarrierFrequency(float frequency);
  void setModulatorFrequency(float frequency);
  void setPitch(int pitch);


private:
  int currentPitch = 60;
};

//==============================================================================

class Synth {
public:
  virtual float calculate();
  virtual void setDetune(float detuneAmount);
  virtual void setFrequency(float frequency);
  virtual void setDelay(float delay);

};

class DetuneSynth : Synth {
public:
  void calculate() override;
  void setDetune() override;
  void setFrequency() override;

};

class WideStereoSynth : Synth {
  void setFrequency() override;
  void calculate() override;
  void setDelay() override;

};


