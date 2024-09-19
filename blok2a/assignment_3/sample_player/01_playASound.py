"""
An example project in which three wav files are used.

------ EXERCISES ------

- What does the function wait_done() do?

- Answer the following question before running the code:
  Do you expect to hear the samples played simultaneously or one after the other?
  Why?

- Alter the code:
  Play the sounds one after the other and then simultaneously.

- Alter the code:
  Ask the user to choice which one of the three samples should be played and
  only play the chosen sample.

- Give yourself a couple of assignments, like playing one of the samples ten
  times before the others are played, playing all samples a given number
  of times or playing the samples one after the other with 1 second between
  them.

"""

# simpleaudio is imported as sa -> shorter name
import simpleaudio as sa

# load audio files
sampleHigh = sa.WaveObject.from_wave_file("../audioFiles/Pop.wav")
sampleMid = sa.WaveObject.from_wave_file("../audioFiles/Laser1.wav")
sampleLow = sa.WaveObject.from_wave_file("../audioFiles/Dog2.wav")

# play high sample
sampleHighPlay = sampleHigh.play()
# wait till sample is done playing
sampleHighPlay.wait_done()

# play mid sample
sampleMidPlay = sampleMid.play()
# wait till sample is done playing
sampleMidPlay.wait_done()

# play low sample
sampleLowPlay = sampleLow.play()
# wait till sample is done playing
sampleLowPlay.wait_done()

