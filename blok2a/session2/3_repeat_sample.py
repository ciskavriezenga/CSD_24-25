import simpleaudio as sa
import time


# Ask the user to enter how many times a sample is to be repeated

# N.B.: input() gives a string which has to be converted to an integer value
number_of_repeats = int(input("Aantal herhalingen: "))

snare = sa.WaveObject.from_wave_file("kit/snare.wav")

# Repeatedly play the sample with a short delay afterwards
for i in range(number_of_repeats):
    play_obj = snare.play()
    time.sleep(0.5)

# Wait for the last note to ring out
play_obj.wait_done()

