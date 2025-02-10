

float Triangle::calculateSample(float phase)
{
  // std::cout << "debug b" << std::endl;
  waveSample = phase * 4.0 - 1.0;
  if(phase >= 0.5) {
    waveSample = -phase * 4 + 3;
  }
  return waveSample;
}


void DetunedSaw::tick() {
  // update phase
  phase += increment;
  if (phase > 1.0f) {
    phase -= 1.0f;
  }

  oscillators[0]->setFrequency(frequency);
  oscillators[1]->setFrequency(frequency + (midiToFrequency(detuneAmt) / 10.f));
  oscillators[2]->setFrequency(frequency - (midiToFrequency(detuneAmt) / 10.f));

  float oscillatorSum = oscillators[0]->getSample() +
                        oscillators[1]->getSample() +
                        oscillators[2]->getSample();

  // assign value to output sample
  sample = (oscillatorSum / 3.f) * amplitude; // * envelopes[0]->getValue();

  // update oscillators and envelope
  for (int i = 0; i < 3; i++) {
    oscillators[i]->tick();
  }
  envelopes[0]->tick();
}


CustomCallback::CustomCallback() : myFMSynth(1, 0), myAdditiveSynth(1)
{
  // Ask user for synth type
  int synthTypeSelection = console_ui.retrieveUserSelection(synthTypeOptions, numSynthTypeOptions);
  chosenSynthType = static_cast<SynthType>(synthTypeSelection);
  if (chosenSynthType == FM_SYNTH)
  {
    numCarriers = console_ui.retrieveValueInRange("Number of carriers", 1, 10);
    numModulators = console_ui.retrieveValueInRange("Number of modulators", 0, 10);
    // Initialize carriers
    for (int i = 0; i < numCarriers; ++i)
    {
      std::cout << "carrier " << i + 1<< ":\n";
      // Retrieve user selection for carrier wave type.
      int waveTypeSelection = console_ui.retrieveUserSelection(waveFormOptions, numWaveFormOptions);
      std::string waveType = waveFormOptions[waveTypeSelection];

      // Retrieve carrier frequency within a specified range from the user.
      float freq = console_ui.retrieveValueInRange("frequency", 20, 20499);

      // Add carrier with specified type, frequency, amplitude, and samplerate.
      myFMSynth.addOscillator(i, waveType, freq, amplitude / numCarriers, samplerate);
    }
    // Initialize modulators
    for (int i = 0; i < numModulators; ++i)
    {
      std::cout << "modulator " << i + 1 << ":\n";
      // Retrieve user selection for modulator wave type.
      int waveTypeSelection = console_ui.retrieveUserSelection(waveFormOptions, numWaveFormOptions);
      std::string modWaveType = waveFormOptions[waveTypeSelection];

      // Retrieve modulation frequency within a specified range from the user.
      float modFreq = console_ui.retrieveValueInRange("modulation frequency", 20, 20499);

      // Retrieve modulation index within a specified range from the user.
      float modIndex = console_ui.retrieveValueInRange("modulation index", 0.1, 10);

      // Add modulator with specified type, frequency, amplitute, index and samplerate
      myFMSynth.addModulator(i, modWaveType, modFreq, amplitude / numModulators, modIndex, samplerate);
    }

  }
  else if (chosenSynthType == ADDITIVE_SYNTH)
  {
    // Ask for number of partials
    int numPartials = console_ui.retrieveValueInRange("Number of partials", 1, 10);
    for (int i = 0; i < numPartials; ++i)
    {
      std::cout << "partial " << i + 1 << ":\n";
      // Retrieve user selection for partial wave type.
      int waveTypeSelection = console_ui.retrieveUserSelection(waveFormOptions, numWaveFormOptions);
      std::string waveType = waveFormOptions[waveTypeSelection];

      // Retrieve partial frequency within a specified range from the user.
      float freq = console_ui.retrieveValueInRange("frequency", 20, 20499);

      // Add partial with specified type, frequency, amplitude, and samplerate.
      myAdditiveSynth.addOscillator(i, waveType, freq, amplitude / numPartials, samplerate);
    }
  }

  // std::cout << "CustomCallback - constructor\n";
}


while (running)
{
  switch (std::cin.get())
  {
    case 'q':
    {running = false;
      jack.end();
      break;}
    case 'c':{
      std::cout << "\n Enter new frequency: ";
      std::cin >> frequency;
      sine1.setFrequency(frequency);
      sine1.getFrequency();
//      std::cout << "Frequency: " << sine1.getFrequency();
//      std::cout << "Frequency 2: " << frequency << std::endl;

      break;
    }
    case 'b':
    {
      sine1.setbeatsPermin(bPm);
      bPm = sine1.getbeatsPermin();
//      std::cout << "BPM is: " << bPm << std::endl;
      break;
    }
    case 'm':
    {
      sine1.play(frequency, bPm);
      break;
    }
  }
}
