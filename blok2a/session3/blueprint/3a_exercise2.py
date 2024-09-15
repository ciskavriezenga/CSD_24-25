import simpleaudio as sa
import time

# expected input:
# first number: number of note durations
# from index 1 to index x: note durations
# last: bpm
# example: 4 1 0.5 1.5 0.5 120


# ___ retrieve all necessary values and lists necessary for playing rhythm ___
# retrieve note durations and bpm from input



# load a sample
sample_plop = sa.WaveObject.from_wave_file("../assets/Plop.wav")

# ___ play rhythm ___
sample_plop.play().wait_done()