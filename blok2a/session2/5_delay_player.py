import simpleaudio as sa
import time

rhythm = []

# Rhythm list contains delays in seconds
# The list can also be filled when it is constructed, but for
# this example we first construct it and add elements afterwards.
rhythm.append(1)
rhythm.append(2)
rhythm.append(1)
rhythm.append(0.5)
rhythm.append(1)
rhythm.append(0.5)
rhythm.append(2)
rhythm.append(1)
rhythm.append(1)
rhythm.append(0.5)
rhythm.append(1)

snare = sa.WaveObject.from_wave_file("kit/snare.wav")

# Use Python's capability to loop over a list and perform actions
#  on every item it gets from the list
for delay in rhythm:
    play_obj = snare.play()
    time.sleep(delay*0.3)

# Wait for the last note to ring out
play_obj.wait_done()


