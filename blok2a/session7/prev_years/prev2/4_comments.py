
# ________________________________________________________________________________________
# SNIPPET 1
# ________________________________________________________________________________________

# _____ FEEDBACK _____
# FEEDBACK: GLOBALS ..... better to not use globals in this way, the data flow is very unclear and error prone
# ____________________
def createNewBeat(): #function that generates a new 4 bar rhythm
    createTimestamps()
    timestampsToSixteenths()
    createInstruments()
    createVelocities()
    createEvents()

# ________________________________________________________________________________________
# SNIPPET 2
# ________________________________________________________________________________________
# _____ FEEDBACK _____
# Many nested ifs in a forloop:
# • this can be written more clearly
# • this looks like a lot of duplicate code.
# ____________________

# ...
    for i in range(stampsBarOne):  # create instruments for first bar
        if sixteenths[i] % 16 == 1:  # Every first beat is probably kick
            if random.randint(0, 100) < 80:
                randomInst = 0  # 0 = Kick
            # _____ FEEDBACK _____
            # BE AWARE! you generate a new random number, is that what you really want?
            # ____________________
            elif 80 <= random.randint(0, 100) <= 90:
                randomInst = 1  # 1 = Snare
            else:
                randomInst = 2  # 2 = HiHat
        elif sixteenths[i] % 8 == 5:  # Every 2nd and 4th beat is probaly snare
            if random.randint(0, 100) < 90:
                randomInst = 1
            elif 90 <= random.randint(0, 100) <= 95:
                randomInst = 0
            else:
                randomInst = 2
        else:
            if random.randint(0, 100) < 50:  # Everything else is most probable HiHat
                randomInst = 2
            elif 50 <= random.randint(0, 100) <= 70:
                randomInst = 0
            else:
                randomInst = 1

        # code to generate 2nd sample (hihat) that will be played simultaneous
        # i chose only for a hihat since i don't want a kick and snare to be played at the same time
        if randomInst != 2:  # if the first sample is not a hiHat
            if random.randint(0, 100) < 50:
                instruments2.append(hiHat)  # 50% chance that a hiHat sample is added to kick or snare
            else:
                instruments2.append("Empty")  # 50% that no extra instrument is added
        else:
            instruments2.append("Empty")  # if the first sample is a hiHat dont add a 2nd hihat

        instruments.append(audioSamples[randomInst])
        instrumentNames.append(sampleNames[randomInst])


 random_select_index([90, 95], [0, 1, 2])

# ___________________________________________
# __________ EXAMPLE FIX / CLEANUP __________
# ___________________________________________
 def randomly_select_index(perc_ranges, indices):
     num = random.randint(0, 100)
     if num < perc_ranges[0]:
        return indices[0]
     elif num < perc_ranges[1]:
         return indices[1]
     else:
         return indices[2]


 if sixteenths[i] % 16 == 1:
     # Every first beat is probably kick - 80% (0), 10% change to add snare (1), else hihat (2)
     random_inst = randomly_select_index([80, 90], [0, 1, 2])
elif sixteenths[i] % 8 == 5:
    # Every 2nd and 4th beat is probaly snare (1), else kick (0) else hihat(2)
    random_inst = randomly_select_index([90, 95], [1, 0, 2])
else:
    # Everything else is most probable HiHat (2), or else add kick (0) or snare (1)
    random_inst = randomly_select_index([50, 70], [2, 0, 1])

# _____ A BIT MORE FEEDBACK _____
# This looks like a regular beat generator - assuming on and offbeat in this way
# every pulse / beat gets an instrument - this is a restriction
# ____________________




# ________________________________________________________________________________________
# SNIPPET 3
# ________________________________________________________________________________________
# original code:
def timestampsToSixteenths():
    global sixteenths
    sixteenths = []
    sixteenths.clear()
    for stamp in timestamps:
        sixteenths.append(round((stamp / ((60/BPM)*0.25)) + 1)) #convert timestamp to stixteenth



# ___________ code with feedback __________
# _____ FEEDBACK _____
# global sixteenths --> use return instead
# ____________________

def timestampsToSixteenths():
    global sixteenths
    sixteenths = []
    # _____ FEEDBACK _____
    # not necessary to clear - just created the sixteenths
    # ____________________
    sixteenths.clear()
    # _____ FEEDBACK _____
    # OEI - global (timestamps and BPM) --> pass timestamps as a parameter to the function
    # ____________________
    for stamp in timestamps:
        # _____ FEEDBACK _____
        # calculating 60 /BPM each time ...
        # why the +1?
        #       (stamp / ((60/BPM)*0.25)) + 1)?????
        # split up line --> makes it more readable
        # ____________________
        sixteenths.append(round((stamp / ((60/BPM)*0.25)) + 1)) #convert timestamp to stixteenth


# ___________________________________________
# __________ EXAMPLE FIX / CLEANUP __________
# ___________________________________________
def ts_to_sixteenth(seq_tdur, bpm):
    seq_sixteenth = []
    # calculate the seconds for onte sixteenth note
    # quarternote time = 60 / bpm, thus sixteenth = 60 * 0.25 / bpm  = 15 / bpm
    sixteenth_tdur = (15 / bpm)

    # transform timestamp to sixteenth
    for ts in timestamps:
        sixteenth = round(ts / sixteenth_tdur)
        # start at index 1, thus add one
        sixteenth += 1
        sixteenths.append(sixteenth)


