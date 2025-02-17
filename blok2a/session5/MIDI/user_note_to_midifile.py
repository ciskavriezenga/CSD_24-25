#
# Demo program for asking user for some note(s), then write them to
#  a MIDI file using midiutil
#   https://pypi.org/project/MIDIUtil
#

from midiutil import MIDIFile

midi_note_nr = 60
velocity = 100

midi_file = MIDIFile(1)

track = 0
time = 0
midi_file.addTrackName(track, time, "Beat Sample Track")
bpm = 120
midi_file.addTempo(track, time, bpm)

# Format:
# mf.addNote(time, duration, velocity)
channel = 0
note_time = 2
duration = 1
midi_file.addNote(track, channel, midi_note_nr, note_time, duration, velocity)

with open("symphony.midi",'wb') as outf:
    midi_file.writeFile(outf)


