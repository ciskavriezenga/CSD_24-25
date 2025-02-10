correctInput = False
# default bpm
bpm = 120
while (not correctInput):
    user_bpm = input("enter a bpm")

    # check if we 'received' an empty string
    if not user_bpm:
        # empty string --> use default
        correctInput = True
    else:
        try:
            bpm = float(user_bpm)
            correctInput = True
        except:
            print("Incorrect input - please enter a bpm (or enter nothing - default bpm)")



print("Succeeded, bpm is: ", bpm)