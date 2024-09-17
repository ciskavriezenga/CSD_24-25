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

# transform time durations to a sequence of timestamps
time_stamps = []
total_dur = 0

for dur in time_durations:
    time_stamps.append(total_dur)
    total_dur = total_dur + dur

print(time_stamps)


# retrieve the first time stamp (if it exist - else exit)
ts = time_stamps.pop(0)

# store the current time
start_time = time.time()

# load a sample
sample_plop = sa.WaveObject.from_wave_file("../assets/Plop.wav")
# iterate through time sequence and play sample
while True:
    t_cur = time.time() - start_time

    if t_cur >= ts:
        sample_plop.play()
        if len(time_stamps) > 0:
            ts = time_stamps.pop(0)
        else:
            break
    time.sleep(0.001)

# wait till last sample is done playing before exit
time.sleep(time_durations[-1])
