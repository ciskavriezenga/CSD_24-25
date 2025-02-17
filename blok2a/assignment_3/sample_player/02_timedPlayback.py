"""
An example project in which three wav files are played after the other with a
pause in between.

------ EXERCISES ------
- Alter the code:
  Write a function that plays the samples a given number of times.
  Call this function.

- Alter the code:
  Change the time in between samples into a random value.
  E.g. wait 0.25, 0.5, or 1 second.
  hint:  there is a standard 'random' package available with a 'random' function
         https://docs.python.org/2/library/random.html
         A standard package does not need to be installed with pip, but it does
         need to be imported when you want to use it.
"""

import simpleaudio as sa
import time

# load audio files into a list
samples = [ sa.WaveObject.from_wave_file("../audioFiles/Pop.wav"),
            sa.WaveObject.from_wave_file("../audioFiles/Laser1.wav"),
            sa.WaveObject.from_wave_file("../audioFiles/Dog2.wav")]


# play samples, wait 1 second in between
for sample in samples:
  print(sample) # display the sample object
  sample.play() # play sample
  time.sleep(1) # wait 1 second

