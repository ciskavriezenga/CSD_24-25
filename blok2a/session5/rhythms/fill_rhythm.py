import random

# the number of pulses to fill with sets of 2's and 3's
num_pulses_input = int(input("Please enter the number of pulses\n"))

seq = []

if num_pulses_input < 2:
    print("Too low number of pulses")
    exit()

num_pulses = num_pulses_input
while num_pulses:
    # add 2's and 3's in a random manner
    if num_pulses >= 3:
        dur = random.randint(2, 3)
        num_pulses -= dur
        seq.append(dur)
    # num_pulse < 3? We can not add 3's anymore, add 2 or adapt last notes
    else:
        if num_pulses == 2:
            seq.append(2)
            num_pulses -= 2
        elif num_pulses == 1:
            if seq[-1] == 2:
                # extend last note with +1
                seq[-1] += 1
            else: # last note is a 3, change it into a 2 and add a 2
                seq[-1] -= 1
                seq.append(2)
            num_pulses -= 1
        else:
            print("THIS SHOULD NEVER HAPPEN! - num_pulses while loop")

if sum(seq) != num_pulses_input:
    print("THIS SHOULD NEVER HAPPEN - incorrect # pulses in the sequence.")

print(seq)
