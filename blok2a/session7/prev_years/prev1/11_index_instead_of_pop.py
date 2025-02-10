
# check if events is not empty
if not events:
    # list contains no items
    exit()

# store the current time
time_zero = time.time()
print("time zero:", time_zero)
# start at index 0 and retrieve reference to current timestamp
index = 0
event = events[index]
ts = event["timestamp"]

# iterate through time sequence and play sample
while True:
    now = time.time() - time_zero
    # did we arrive at the new timestamp?
    if(now > ts):
        # play sample and fetch new event and timestamp
        samples[event["sample_index"]].play()
        if index >= len(events):
            event = events[index]
            ts = event["timestamp"]
        else:
            # NOTE: or, if you want to loop, you could repeat at index 0
            # and then add an time-offset for the current bar
            break

    time.sleep(0.001)
