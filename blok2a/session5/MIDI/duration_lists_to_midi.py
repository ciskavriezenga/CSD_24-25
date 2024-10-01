#
#   https://pypi.org/project/MIDIUtil
#

from midiutil import MIDIFile


# a simplifications of note_durations lists
kick_note_durations = [1, 1, 2]
kick_qnote_offset = 0
snare_note_durations = [0.5, 1, 1, 0.5]
# snare does not start at first note but starts with a qnote rest
snare_qnote_offset = 1


# set the necessary values for MIDI util
velocity=80
track = 0
channel = 9  # corresponds to channel 10 drums
bpm = 120

# create the MIDIfile object, to which we can add notes
mf = MIDIFile(1)
# set name and tempo
time_beginning = 0
mf.addTrackName(track, time_beginning, "Beat Sample Track")
mf.addTempo(track, time_beginning, bpm)




# NOTE: DUPLICATE CODE below, would be better to place stuff below in a function

# ___ add the kick durations to the note
# set the time to kick offset in case the kick does not start at the beginning
time = kick_qnote_offset

# add the notes for the kick
kick_midi_pitch = 35
for dur in kick_note_durations:
    mf.addNote(track, channel, kick_midi_pitch, time, dur, velocity)
    # increment time based on the duration of the added note
    time = time + dur


# ___ add the kick durations to the note
# reset the time to snare offset in case the snare does not start at the beginning
time = snare_qnote_offset
# add the notes for the snare
snare_midi_pitch = 38
for dur in snare_note_durations:
    mf.addNote(track, channel, snare_midi_pitch, time, dur, velocity)
    # increment time based on the duration of the added note
    time = time + dur


with open("duration_lists.midi",'wb') as outf:
    mf.writeFile(outf)
