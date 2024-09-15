import simpleaudio as sa
import time

# set values and create lists necessary for playing rhythm
note_durations = [1, 0.5, 1, 0.5, 0.5]
bpm = 120
print("note_durations:", note_durations)

# calculate duration of a quarternote in seconds
quarternote_dur = 60.0 / bpm
print("bpm:", bpm, "quarternote_dur", quarternote_dur)

# transform note durations to sequence of time durations
time_durations = []
for note_dur in note_durations:
    time_durations.append(quarternote_dur * note_dur)

print("time_durations", time_durations)

# load a sample
sample_plop = sa.WaveObject.from_wave_file("../assets/Plop.wav")

# transform time durations to a sequence of timestamps
# todo

# retrieve the first time stamp (if it exist - else exit)
# todo

# store the current time
# todo

# iterate through time sequence and play sample
# todo

# wait till last sample is done playing before exit
time.sleep(time_durations[-1])
