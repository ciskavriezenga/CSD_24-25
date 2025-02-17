import simpleaudio as sa
import time

# expected input:
# first number: number of note durations
# from index 1 to index x: note durations
# last: bpm
# example: 4 1 0.5 1.5 0.5 120


# ___ retrieve all necessary values and lists necessary for playing rhythm ___
# retrieve note durations and bpm from input
num_notes = input("Enter num notes\n")
note_durations = list()

for i in range(int(num_notes)):
    note_durations.append(float(input("Enter note duration\n")))

print("note_durations:", note_durations)

# retrieve BPM and calculate corresponding quarternote duration
bpm = float(input("Enter BPM\n"))
quarternote_dur = 60.0 / bpm
print("bpm:", bpm, "quarternote_dur", quarternote_dur)

# transform note durations to sequence of time durations (sec)
time_durations = []
for note_dur in note_durations:
    time_durations.append(quarternote_dur * note_dur)

print("time_durations", time_durations)

# ___ play rhythm ___
# load a sample
sample_plop = sa.WaveObject.from_wave_file("../assets/Plop.wav")

# play sequence
for time_dur in time_durations:
    # play sample and pause according to time duration
    sample_plop.play()
    time.sleep(time_dur)
