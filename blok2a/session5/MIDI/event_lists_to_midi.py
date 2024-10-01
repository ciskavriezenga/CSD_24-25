#
#   https://pypi.org/project/MIDIUtil
#

from midiutil import MIDIFile


# short hardcoded list with events, hardcoded for the sake of this example
events = [
    {
        'note_dur': 1.5,
        'instr_name': "kick",
        'timestamp': 0
    },
    {
        'note_dur': 2,
        'instr_name': "snare",
        'timestamp': 0.5
    },
    {
        'note_dur': 2.5,
        'instr_name': "kick",
        'timestamp': 0.75
    },
    {
        'note_dur': 1,
        'instr_name': "snare",
        'timestamp': 1.5
    }
]




# set the necessary values for MIDI util
velocity=80
track = 0
channel = 9 # corresponds to channel 10 drums
bpm = 120


# create the MIDIfile object, to which we can add notes
mf = MIDIFile(1)
# set name and tempo
time_beginning = 0
mf.addTrackName(track, time_beginning, "Beat Sample Track")
mf.addTempo(track, time_beginning, bpm)

# variables necessary for transforming events to midi output
qnote_dur = 60 / bpm
instr_midi_pitch = {
    "kick": 35,
    "snare": 38
}


for event in events:
    # transform time (sec) to (qnote)
    qnote_time = event["timestamp"] / qnote_dur
    instr_name = event["instr_name"]
    mf.addNote(track, channel, instr_midi_pitch[instr_name], qnote_time,
        event['note_dur'], velocity)

with open("events_lists.midi",'wb') as outf:
    mf.writeFile(outf)
