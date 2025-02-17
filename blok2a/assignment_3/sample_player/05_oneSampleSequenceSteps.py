"""
An example project in which a sequence of one bar is played, using only one audio file.
  - One bar, time signature: 3 / 4
  - 3 * 4 sixteenth notes per bar = 12 'steps'.
    Steps correspond with equally spaced 16th notes. This defines the grid, or
    the highest time resolution we will use.

------ EXERCISES ------
- Run the code, read the code and answer the following question:
  This script does not use a list with time intervals, but does play a
  rhythm. Explain how this works.

- Alter the code:
  Fix the bug that occurs: "IndexError: pop from empty list"
"""

import simpleaudio as sa
import time
import random

# load an audio file and store it into a list
# note: using a list is a preparation for the next assignment in which we
# will use multiple audio files
samples = [sa.WaveObject.from_wave_file("../audioFiles/Pop.wav")]

bpm = 120
# calculate quarterNote with bpm
quarterNote = 60 / bpm

# number of quarterNotes per bar (time signature: 3 / 4 = 3 quarterNotes per bar)
quarterNotesPerBar = 3

# number of steps per quarterNote (4 steps per quarterNote -> using sixteenth notes)
stepsPerQuarterNote = 4

# calculate stepDuration
stepDuration = quarterNote / stepsPerQuarterNote

# calculate the number of steps (16th notes) in a bar
stepsPerBar = stepsPerQuarterNote * quarterNotesPerBar

# create a list with a rhythm: the steps at which the sample will be played
# Remember we have a maximum of 12 steps in a bar.
sequence = [0, 2, 4, 8, 11]

# retrieve first step of the bar
# NOTE: pop(0) returns the element at index 0 and removes it from the list
step = sequence.pop(0)

# play the sequence
for currentStep in range(int(stepsPerBar)):
  print("Current step: ", currentStep)
  if(currentStep == step):
    samples[0].play()
    # retrieve the next step at which we need to play a sample
    step = sequence.pop(0)

  time.sleep(stepDuration)

