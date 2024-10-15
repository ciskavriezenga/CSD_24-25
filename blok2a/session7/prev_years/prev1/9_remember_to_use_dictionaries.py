
"""

TODO
• How can you replace line 17 - 27 with one line by using a dictionary?
• Is line 34 redundant? Why?
• line 23 and 26, a lot of space characters, what about using \t?
• why is the forloop not efficient? How could this be improved? 
"""


# start the loop
while True:
    now = time.time() - time_zero
    for i in timeStamps:
        #if the time matches a timeStamps, play the sample attached to it (kick,snare or hihat).
        if (now >= i["timestamps"]):
            if i["instrument"] == 'Kick':
                Kick.play()
                print("kick")
            if i['instrument'] == 'Snare':
                Snare.play()
                print("                         snare")
            if i['instrument'] == 'HiHat':
                HiHat.play()
                print("                                                         hihat")

            #Remove the timestamps when it played.
            timeStamps.remove(i)

            #if the timeStamps are empty, fill it with a copy of the loop so it keeps looping.
            if timeStamps == []:
                print("---------")
                time_zero = time.time()
                now = time.time() - time_zero
                timeStamps = copyStamps
                copyStamps = timeStamps.copy()
