//
// Created by Dean on 13/12/2024.
//
#pragma once

class computerSynth {
public:
  computerSynth() {

  }
  // Functie waar ik de output sample wil berekenen om nar de output te sturen
  berekenDeSample(){
    a = mySecondSynth.berekenDeSample(); // calculate a sample first with the second synth
    a_2 = my_first_synth.berekenDeSample(); // calculate a_2 sample now

    my_first_synth.set_frequency(frek); //update de frequency van de synthesizer
    mySecondSynth.set_frequency(frek); //update de frequency van deze synthesizer
    my_first_synth.setAmp(0.2); // make sure the amplitude is nice
    mySecondSynth.setAmp(0.5); // deze is wat luider dan de vorige
    // the two samples are added together to the output
    sample = a + a_2; // :- )
  }

  void setFreq(int freq){
    if (ISITREADY == true){
      frek = freq;
    } else if (ISITREADY == !true);
  }

  float x () {
    f += d;
    if(f > 1.0f) {
      f -= 1.0f;
    }
    return sin(p * 2 * f) * a;
  }

  void doTheThing(float thing){
    this->thing = thing;
  }

private:
  float a = 0;
  float a_2 {0.0};
  float sample;
  float frek {430};
  float thing;

  bool ISITREADY {false};

  Synth my_first_synth;
  Synth mySecondSynth;
};