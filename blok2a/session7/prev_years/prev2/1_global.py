import random

# _____ FEEDBACK _____
# prevent global lists - present an empty list as parameter or split up your function
# AND: in this example - noteV is used nowhere else
# ____________________

def noteGen(bpmInput):  # creates a random list of note values
    global timeListK, timeListS, timeListH
    global noteV


    # _____ FEEDBACK _____
    # unclear variable name: what does noteV mean?
    # ____________________
    noteV = [0.25, 0.5, 1]

    # _____ FEEDBACK _____
    # unclear variable name: what does bpmNow mean?
    # ____________________
    bpmNow = 60 / bpmInput

    # _____ FEEDBACK _____
    # Duplicate code!
    # ____________________

    kickR = [random.choice(noteV) for i in range(16)]
    snareR = [random.choice(noteV) for i in range(16)]
    hihatR = [random.choice(noteV) for i in range(16)]

    # for i in range(16):
    #     rithms.append(random.choice(noteV))

    timeListK = []
    timeListS = []
    timeListH = []

    for dur in kickR:
        timeListK.append(bpmNow * dur)  # creates the timelist for the three samples

    for dur in snareR:
        timeListS.append(bpmNow * dur)

    for dur in hihatR:
        timeListH.append(bpmNow * dur)

    # _____ FEEDBACK _____
    # why return it if you made it global?
    # ____________________
    return (timeListK, timeListS, timeListH)


# ___________________________________________
# __________ EXAMPLE FIX / CLEANUP __________
# ___________________________________________

def dur_to_tdur(seq_dur, bpm):
    seq_tdur = []
    note_tdur = 60 / bpm
    for dur in seq_dur:
        seq_tdur.append(dur * note_tdur)
    return seq_tdur

# creates a random list of note durations expressed in time (s)
# par note_dur_options: a list with the note duration options
def gen_sequence(note_dur_options, bpm):
    # generate list with quarter notes durations based on the allowed options
    seq_dur = [random.choice(note_dur_options) for i in range(16)]
    return dur_to_tdur(seq_dur, bpm)

bpm = 120
dur_options = [0.25, 0.5, 1]
# NOTE: the code below can be viewed as duplicate code - see example 2_while.py for a FIX
tdur_kick = gen_sequence(dur_options, bpm)
tdur_snare = gen_sequence(dur_options, bpm)
tdur_hihat = gen_sequence(dur_options, bpm)

