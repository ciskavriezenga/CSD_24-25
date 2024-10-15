
"""

TODO
• SEARCH FOR:
    • the redundant check in the while loop condition
    • the redundant transform
    (considering this could be done in an earlier stage)


"""

def run(self):
    self.on = True
    print("Starting " + self.name)
    zeroTime = time.time()

    # the i is used to determine the time stamp that should be used
    i = 0

    # start a time counter and look if the timestamps list is equal to the current time
    while True and self.on:
        now = time.time() - zeroTime
        #Read time stamp from event
        if(now >= float(self.eventList[i]['timestamp'])):
            self.eventHandler(self.eventList[i])
            i = i + 1
            # if the i is at the end of the given list reset i and zero_time
            if i == len(self.eventList):
                i = 0
                zeroTime = time.time()
        # update time
        time.sleep(0.001)
    # wait until the last sample is done playing
