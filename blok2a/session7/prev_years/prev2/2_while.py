# ________________________________________________________________________________________
# SNIPPET 1
# ________________________________________________________________________________________
import random

#the program placed in a while loop to be able to keep creating different sequences.
while True:

    #UI for input time signature
    time_sig = input("Fill in a irregular time signature for the sequence. Choose between 5/4 and 7/8: ")

    print("Time Signature is: ", time_sig)

    # _____ FEEDBACK _____
    # Some of the variables used in this while are not necessary to re-assign each time
    # you can place these above, thus outside the while loop
    # the same accounts for the functions - you can define these outside the while loop
    # this will improve the readability of your code highly
    # ____________________
    #rhythm generation
    #euclidean steps for time signatures
    num_steps_78 = 7
    num_steps_54 = 5
    #euclidean notes per steps
    num_notes_54 = 4
    num_notes_78 = 8

    #function for calculating durations based on time signature
    #To do: Rotation + Variations
    def calculate_durations(steps,notes):
        note_durations = []
        duration16th = int(steps/notes)
        note_durations =[duration16th]*notes
        rest_value = steps - (notes * duration16th)
        for i in range(rest_value):
            note_durations[i] += 1
        return(note_durations)

# ________________________________________________________________________________________
# SNIPPET 2
# ________________________________________________________________________________________

# _____ FEEDBACK about snippet _____
# Full snippet of code below can be shortified!
# ____________________

#euclidean steps for time signatures
num_steps_78 = 7
num_steps_54 = 5

# _____ FEEDBACK _____
# hmm why 4 and 8?:
# 4 and 8 refers to the duration of the 7 or 5 (eight or quarter note)
# however, with respect to euclidean rhythms -
#   e.g. for 7/8 you can use 7 pulses and 7 notes, not 8
# ____________________
#euclidean notes per steps
num_notes_54 = 4
num_notes_78 = 8

# ...

if time_sig == "5/4":
    note_durations_kick = calculate_durations(num_steps_54,num_notes_54)
    note_durations_snare = calculate_durations(num_steps_54,ra.randrange(1,4))
    note_durations_hat = calculate_durations(num_steps_54,ra.randrange(1,4))

if time_sig == "7/8":
    note_durations_kick = calculate_durations(num_steps_78,num_notes_78)
    note_durations_snare = calculate_durations(num_steps_78,ra.randrange(1,8))
    note_durations_hat = calculate_durations(num_steps_78,ra.randrange(1,8))


#...

loop_dur_list(note_durations_kick, loop_amount)
loop_dur_list(note_durations_snare, loop_amount)
loop_dur_list(note_durations_hat, loop_amount)

# ...

#executing functions for converting values to timestamps
time_durations_kick = note_dur_to_td(note_durations_kick,bpm)
time_durations_snare = note_dur_to_td(note_durations_snare,bpm)
time_durations_hat = note_dur_to_td(note_durations_hat,bpm)
# print("The Time Durations between the notes are:",time_durations)
timestamps_kick = time_dur_to_ts(time_durations_kick)
timestamps_snare = time_dur_to_ts(time_durations_snare)
timestamps_hat = time_dur_to_ts(time_durations_hat)
# print("The timestamps are:",timestamps)
ts_kick_events = create_events(kick_dict["Instrument"],timestamps_kick,kick_dict["Name"],note_durations_kick)
ts_snare_events = create_events(snare_dict["Instrument"],timestamps_snare,snare_dict["Name"],note_durations_snare)
ts_hat_events = create_events(hat_dict["Instrument"],timestamps_hat,hat_dict["Name"],note_durations_hat)

#add all the events to a combined list
all_events_list = ts_kick_events + ts_snare_events + ts_hat_events


# ___________________________________________
# __________ EXAMPLE FIX / CLEANUP __________
# ___________________________________________
#Samples
samples = {
    'kick' : sa.WaveObject.from_wave_file("assets/SD_Kick_Battalion.wav"),
    'snare': sa.WaveObject.from_wave_file("assets/SD_Snare_Bewitch.wav"),
    'hihat': sa.WaveObject.from_wave_file("assets/SD_ClHat_Cherry.wav")
}

# The top number determines how many beats are in a measure, while the bottom number determines what type of note gets the beat.
# retrieve number of beats per measure and the type of note of one beat
# e.g. 5/4 --> num_beats is 5 and beat_note_type = 4
# hardcoded in sake of a clear example
num_beats = 7
beat_note_type = 8
# store the names of the three instruments for which we will generate events
names = ['kick', 'snare', 'hihat']
# e.g. use a density to determine the number of notes for euclidean rhythm generation
note_densities = {
    'kick': [0.2, 0.3],
    'snare': [0.1, 0.4],
    'hihat': [0.5, 0.9]
}

#generate events
events = []
for name in names:
    # calculate the range for the number of notes to generate
    # using the number of beats as maximum number of pulses
    # and applying the range of the given instrument
    num_notes_min = round(num_beats * note_densities[name][0])
    num_notes_max = round(num_beats * note_densities[name][1])
    num_notes = random.randint(num_notes_min, num_notes_max)

    # retrieve the durations
    durations = calculate_durations(num_beats, num_notes)

    # repeat the bar - loop_amount times
    loop_dur_list(durations, loop_amount)

    #transform to events
    time_durations = note_dur_to_td(durations,bpm)
    timestamps = time_dur_to_ts(time_durations, bpm)
    # NOTE: slightly adapted events format - see samples dictionary above,
    # name is sufficient to playback correct sample
    events.append(create_events(timestamps, name, durations))
