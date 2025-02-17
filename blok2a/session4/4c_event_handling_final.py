#
# Example demonstrating the use of Python dictionaries for creating
#  bundles of information describing playable events
#
# A Python dictionary is a way of grouping information while preserving
#  both the key to each item and its value. We can use the key to access a
#  piece of information.
#
# Events are things that happen due to actions from outside
#  (e.g. a user presses a button) or things that we want to happen, so
#  these are initiated by our program (e.g. a note that needs to sound at
#  some moment)
#


#
# Here is someone reduced to a dictionary :-)
#
# Keys : name, organisation and role.
#  Each key has a value that can be read or changed.
#

me = {
'name': 'Marc',
'organisation': 'HKU',
'role': 'student'
}

# Try the following lines in ipython and play around with this dictionary:
#  add a field, change a value, read and print some information.
me
print(me)
me['name']
me['role']='teacher'
print(me)

############################################
#
# And now for some sound
#
#

import simpleaudio as sa
import time


#
# Load instrument sound files
#
hihat = sa.WaveObject.from_wave_file("../assets/hihat.wav")
snare = sa.WaveObject.from_wave_file("../assets/snare.wav")
kick = sa.WaveObject.from_wave_file("../assets/kick.wav")


snare_event = {
'timestamp': 1000, # msec w.r.t start of program
'instrumentname': "snare", # name of instrument in text
'instrument': snare, # reference to sound file
'velocity': 82, # numeric MIDI-based, 0-127
'duration': 500 # msec
}

kick_event = {
'timestamp': 2000, # msec w.r.t start of program
'instrumentname': "kick", # name of instrument in text
'instrument': kick, # name of instrument in text
'velocity': 71, # numeric MIDI-based, 0-127
'duration': 100 # msec
}


# create a note handler function
# This function knows how to handle note events that contain information
#  about the name of the note (or in this case instrument), the sound file
#  to be played and some properties we don't use for this example.
#
def handle_note_event(event):
    print(event['instrumentname'])
    event['instrument'].play()


# call the note handler for each event
# We will use the time stamps later on.
handle_note_event(snare_event)
time.sleep(0.1)
handle_note_event(kick_event)

#
# Exercise:
# - add a hihat event and play it
# - extract the time stamp from each event before you give it to the event
# handler and use these for calling the event handler when it is time to
# handle the event (and play the sound)
#

# make sure program doesn't end before samples have finished playing
time.sleep(1)

