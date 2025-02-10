import simpleaudio as sa
import time

# expected input:
# first number: number of note durations
# from index 1 to index x: note durations
# last: bpm
# example: 4 1 0.5 1.5 0.5 120


# ___ retrieve all necessary values and lists necessary for playing rhythm ___
# retrieve note durations and bpm from input
num_repeats = int(input("Please enter the number of times you want to playback your rhythm: "))

num_notes = int(input("Please enter the number of notes in the rhythm: "))

note_durs = []
for i in range(num_notes):
    note_dur = float(input(f"Please enter a note value for note number {i + 1}: "))
    note_durs.append(note_dur)

bpm = float(input("Please enter the bpm: "))



# transform note durations into time durations
quarternote_dur = 60 / bpm
time_durs = []
for note_dur in note_durs:
    time_durs.append(note_dur * quarternote_dur)



# playback!!
# load a sample
sample_plop = sa.WaveObject.from_wave_file("../assets/Plop.wav")
for t_dur in time_durs:
    sample_plop.play().wait_done()
    time.sleep(t_dur)
