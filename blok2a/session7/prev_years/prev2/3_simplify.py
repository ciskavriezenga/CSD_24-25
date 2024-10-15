# ________________________________________________________________________________________
# SNIPPET 1
# ________________________________________________________________________________________

# _____ FEEDBACK _____
# I need to read the below multiple times - to follow it, so either
# - it is too complex and can be written more clearly
# - the complexity is necessary - then it definitely lacks comments
# ____________________

while not correct_input:
    change_default_bpm = input("Default bpm = 120. Want to adjust? [y/n]: ", )

    # _____ FEEDBACK _____
    # nice to use a tuple :D THUMBSUP
    # but let's split up these 2 nested whiles for the sake of readability
    # ____________________
    if change_default_bpm in ("Y", "y"):
        while (not correct_bpm):
            user_bpm = input("Enter bpm: ", )
            # _____ FEEDBACK _____
            # What about the allowed range?
            # ____________________
            if not user_bpm:
                correct_bpm = True
            else:
                try:
                    bpm = float(user_bpm)
                    correct_bpm = True
                    break
                except:
                    print("Incorrect bpm. Try again:. ")
        print("bpm is: ", bpm)
        correct_input = True
    elif change_default_bpm in ("N", "n"):
        print("Ok. Bpm is still {bpm}. " )
        correct_input = True
    else:
        print("Incorrect input. Try again. ")
        # _____ FEEDBACK _____
        # redundant - no need to reset correct_input to false
        # ____________________
        correct_input = False

# ___________________________________________
# __________ EXAMPLE FIX / CLEANUP __________
# ___________________________________________
# ask user to use default BPM or enter a custom BPM

def retrieve_custom_bpm():
    correct_bpm = False
    while not correct_bpm:
        user_bpm = input("Enter bpm between 40 and 200: ")
        try:
            bpm = float(user_bpm)
            if bpm >= 40 and bpm <= 200:
                correct_bpm = True
            else:
                ("Please enter a bpm between 40 an 200")
        except:
            print("Incorrect bpm. Try again:. ")
    return bpm

def retrieve_bpm():
    # default value
    bpm = 120

    # ask user to either enter custom bpm or to use the default
    user_input_correct = false
    while not user_input_correct:
        use_default_bpm = input(f"Default bpm = {bpm} Want to adjust? [y/n]: ")
        if use_default_bpm in ("Y", "y"):
            bpm = retrieve_bpm()
            user_input_correct = True
        elif change_default_bpm in ("N", "n"):
            print(f"Ok. Bpm is still {bpm}. ")
            user_input_correct = True
        else:
            print("Incorrect input. Try again. ")
    return bpm

bpm = retrieve_bpm()



# ________________________________________________________________________________________
# SNIPPET 2
# ________________________________________________________________________________________

# original snippet
# Function to calculate durations to 16th stamps
def note_to_dur(src):
    dst = list(range(len(src)))
    dst.insert(0,0)
    for i in range(len(src)):
        dur = src[i] * 4
        dur = dur * (60 / bpm /4)
        dst[i + 1] = dst[i] + dur
    dst.pop()
    return dst


# _____ Snippet with FEEDBACK _____
# OEF - looks complex,
# if you do want to combine the transformation to timestamps
# it can be written more clearly
# ____________________

# Function to calculate durations to 16th stamps
def note_to_dur(src):
    dst = list(range(len(src)))
    # _____ FEEDBACK _____
    # good to add a comment for this insert - 0,
    # ____________________
    dst.insert(0,0)
    for i in range(len(src)):
        dur = src[i] * 4
        dur = dur * (60 / bpm /4)
        dst[i + 1] = dst[i] + dur
    # _____ FEEDBACK _____
    # good to add a comment to explain the pop
    # ____________________
    dst.pop()
    return dst

# ___________________________________________
# __________ EXAMPLE FIX / CLEANUP __________
# ___________________________________________

# Function to calculate 16th durations to timestamps
def sixteenth_to_ts(sixteenth_durs):
    timestamps = []

    # calculate the multiplication value to transform sixteenth duration to time duration
    time_multiplier = 60 / bpm / 4

    # transform the 16th duration to timestamps
    tdur_sum = 0
    for dur in sixteenth_durs:
        # add the current sum - this means we start at value 0 for the first note
        timestamps.append(tdur_sum)
        # accumulate the duration in time to calculate the next timestamp
        tdur_sum += dur * time_multiplier

    return timestamps


