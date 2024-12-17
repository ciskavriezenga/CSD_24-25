//
// Created by Dean on 13/12/2024.
//

float FMSynth::getSample()
{
  float sample = 0.0f;

  // Loop through each carrier oscillator
  for (int i = 0; i < numOscillators; ++i) {
    float modulation = 0.0f;

    // Apply modulation from each modulator to the carrier
    for (int j = 0; j < numModulators; ++j) {
      modulation += modulatorBank[j]->getSample() * modulationIndices[j];
    }

    // Adjust carrier frequency by modulation
    float originalFreq = oscillatorBank[i]->getFreq();
    oscillatorBank[i]->setFreq(originalFreq + modulation);

    // Get the sample from the carrier
    sample += oscillatorBank[i]->getSample();

    // Reset the carrier frequency to its original value
    oscillatorBank[i]->setFreq(originalFreq);
  }
  return sample;
}

void Melody::setbeatsPermin(int bPm)
{
  cout << "\n Enter BPM: ";
  cin >> bpm;
  bPm = 60000 / bpm;
  this->bPm = bPm;
}

void CustomCallback::process(AudioBuffer buffer) {
  for (int i = 0; i < buffer.numFrames; ++i) {
    // Get sample and tick based on the synth type
    if (chosenSynthType == FM_SYNTH) {
      buffer.outputChannels[0][i] = myFMSynth.getSample();
      myFMSynth.tick();
    } else if (chosenSynthType == ADDITIVE_SYNTH) {
      buffer.outputChannels[0][i] = myAdditiveSynth.getSample();
      myAdditiveSynth.tick();
    }
    if(frameIndex >= noteDelayFactor * samplerate) {
      // Reset the frame index and update the pitch based on the synth type.
      if (chosenSynthType == FM_SYNTH) {
        updatePitch(melody, myFMSynth);
      } else if (chosenSynthType == ADDITIVE_SYNTH) {
        updatePitch(melody, myAdditiveSynth);
      }
      frameIndex = 0;
    }
    else {
      // Increment the frame index.
      frameIndex++;
    }
  }
}

void Square::tick() {
  phase += frequency / samplerate;
  sampletje = sin(M_PI * 2 * phase);
  if(sampletje >= 0){
    sample = 1;
  }else{
    sample = -1;
  }
}
