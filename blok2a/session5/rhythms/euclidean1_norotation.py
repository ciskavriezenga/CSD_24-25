# simple euclidean example, without rotation
num_pulses = 11
num_notes = 4


# calculate duration of a note, expressed in 16th
dur = int(num_pulses / num_notes)
# fill list num_notes times with the duration value
sequence = [dur] * num_notes

"""
# NOTE: this outcommented snippet results in the same as the line above,
# fill list num_notes times with the duration value
sequence = []
for i in range(num_notes):
  sequence.append(dur)
"""
# calculate the rest value and distribute these amongst the stored durations
rest_value = num_pulses - (num_notes * dur)
for i in range(rest_value):
    sequence[i] += 1

print(sequence)
