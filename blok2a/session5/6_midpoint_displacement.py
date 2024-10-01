from midiutil import MIDIFile #   https://pypi.org/project/MIDIUtil
import random
import numpy as np


# _________ split function based on midpoint displacement algorithm _________
def split_note(notes, index, random_range):
    # splits a note at the passed index, based on midpoint displacement algorith
    # notes: a list with note dictionaries
    # index: the index of the note to split
    # random_range: a floating point defining the range of the randomness

    # make sure that the index is not pointing at the last note
    if(index >= len(notes) - 1): return

    # calculate new duration for the note and
    # the rest duration value for the new note
    # split amount --> divide in half, in a quarter, in an eighth
    # for reference of the numpy.random.choice function see:
    # https://numpy.org/doc/stable/reference/random/generated/numpy.random.choice.html
    split_amount = np.random.choice([0.5, 0.25, 0.125], p =[0.45, 0.45, 0.1])
    dur = notes[index]["qnote_dur"]
    new_dur = dur * split_amount
    rest_dur = dur - new_dur
    print("dur:", dur, "new_dur:", new_dur, "rest_dur:", rest_dur)
    # assign new duration to the note to split
    notes[index]["qnote_dur"] = new_dur

    # calculate new pitch, steps:
    # 1. interpolate linearly between pitch of note at current index and next
    # 2. add random value, based on passed randomness
    pitch1 = notes[index]["midi_pitch"]
    pitch2 = notes[index + 1]["midi_pitch"]
    # interpolate new pitch and round the result
    new_pitch = int((pitch2 - pitch1) * split_amount + pitch1 + 0.5)
    # add random value to the new pitch
    new_pitch = new_pitch + random.randint(-1 * random_range, random_range)
    notes.insert(index + 1, {"midi_pitch": new_pitch, "qnote_dur": rest_dur})

# _________ prepare for midpoint displacement _________
note_sequence = [
    {"midi_pitch": 60, "qnote_dur": 16},
    {"midi_pitch": 60, "qnote_dur": 4}
]

# start with maximum displacement of 12
# NOTE: example does not use a scale, for the sake of simplicity
random_range = 12

# each iteration we lower the random range depending on random_diminisher value
random_diminisher = 0.5


# _________ apply midpoint displacement _________
# outer loop: the number of midpoint displacement iterations of the sequence
for i in range(3):    
    # calculate 2 ^ i to retrieve the amount of splits in the current iteration
    num_splits = 2 ** i
    # debugging: keep track of splitted note indices
    splitted_indices = []
    # split notes
    for j in range(num_splits):
        index = j * 2
        split_note(note_sequence, index, random_range)
        # debugging: keep track of splitted note indices
        splitted_indices.append(index)

    # lower the random range
    random_range = int(random_range * random_diminisher + 0.5)
    # debugging: print the note indices that are splitted
    print("splitted_indices:", splitted_indices)


# _________ create midi output _________
# create your MIDI object
# only 1 track
mf = MIDIFile(1)
# the only track
track = 0
# start at the beginning
time = 0
channel = 0
volume = 60
mf.addTrackName(track, time, "Sequence based on midpoint displacement")
mf.addTempo(track, time, 120)

# add the notes from the note_sequence
for note in note_sequence:
    dur = note["qnote_dur"]
    mf.addNote(track, channel, note["midi_pitch"],
                time, dur, volume)
    # increment time based on the duration of the added note
    time = time + dur

# write midifile to disk
with open("mysong.mid",'wb') as outf:
    mf.writeFile(outf)
