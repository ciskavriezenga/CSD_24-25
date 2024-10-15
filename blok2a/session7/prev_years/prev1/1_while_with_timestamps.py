import time
import simpleaudio as sa

# load sample
sample_pop = sa.WaveObject.from_wave_file("./assets/Pop.wav")

# list with a rhythmic sequence in quarter notes
note_dur_seq = [1.5, 1, 1, 0.5]
bpm = 120

# function to transform a sequence with durations in quarter notes into
# a sequence with durations in time (sec.)
def to_time_dur(src_seq, bpm):
    dst_seq = []
    dur_multiplyer = 60.0 / bpm

    # iterate through the source sequence, add duration values to destiation seq
    for note_dur in src_seq:
        dst_seq.append(note_dur * dur_multiplyer)

    return dst_seq


# function to transform a sequence with durations in time (sec.) into
# a sequence with timestamps
def to_timestamp_seq(src_seq):
    dst_seq = []
    timestamp = 0
    # iterate through the source sequence, sum durations and store these as
    # timestamp in the destination Sequence
    for time_dur in src_seq:
        dst_seq.append(timestamp)
        timestamp = timestamp + time_dur

    return dst_seq

# call the to_time function and store the restulting sequence
time_dur_seq = to_time_dur(note_dur_seq, bpm)
# transform the list with note duration into a list with timestamps
timestamp_seq = to_timestamp_seq(time_dur_seq)

print("Sequence with quarter note values:", note_dur_seq)
print("Sequence with duration values in seconds:", time_dur_seq)
print("Sequence with timestamp values in seconds:", timestamp_seq)


# retrieve the first time stamp
if timestamp_seq:
    ts = timestamp_seq.pop(0)
else:
    # list contains no items
    exit()

# store the current time
time_zero = time.time()
print("time zero:", time_zero)

# iterate through time sequence and play sample
while True:
    now = time.time() - time_zero
    if(now > ts):
        sample_pop.play()
        if timestamp_seq:
            ts = timestamp_seq.pop(0)
        else:
            break

    time.sleep(0.001)
