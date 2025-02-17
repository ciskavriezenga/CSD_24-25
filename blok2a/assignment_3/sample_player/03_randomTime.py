"""
An example project in which three wav files are played one after the other with a
break in between of a random duration.
Used durations are: 0.125, 0.25 and 0.5 seconds

------ EXERCISES ------
- Alter the code:
  Add a noteDurations list, with the numbers 0.25, 0.5, 1.0. These values stand
  for a sixteenth, eighth and quarter note.
  Add a bpm variable to the project and calculate the corresponding timeIntervals
  accordingly. Add these values to the timeIntervals list, instead of its
  current values.

- Alter the code:
  Write a function around the playback forloop, which takes two arguments:
  - a list with samples
  - a list with timeIntervals
  Use this function.
"""

import simpleaudio as sa
import time
import random

# load audio files into a list
samples = [sa.WaveObject.from_wave_file("../audioFiles/Pop.wav"),
              sa.WaveObject.from_wave_file("../audioFiles/Laser1.wav"),
              sa.WaveObject.from_wave_file("../audioFiles/Dog2.wav")]

# create a list to hold the timeIntervals 0.25, 0.5, 1.0
timeIntervals = [0.25, 0.5, 1]


# play samples and wait in between (random duration)
for sample in samples:
  print(sample)
  sample.play()

  # get a random value to be used as sample index
  randomIndex = random.randint(0, 2)

  # dislay the selected timeInterval
  print("waiting: " + str(timeIntervals[randomIndex]) + " seconds.")

  # wait some time
  time.sleep(timeIntervals[randomIndex])

