import simpleaudio as sa

snare = sa.WaveObject.from_wave_file("kit/snare.wav")

play_obj = snare.play()
play_obj.wait_done()

