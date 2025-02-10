"""
NOTES:
• timestamp key in event dictionary is not an actual timestamp but a beat_index

TODO
• SEARCH FOR:
    • unneccessary forloop (similar to example 2)
    • duplicate code
    • how many times do you expect the while loop to be run per second?


"""


def counter():
    count = 0
    tijd = time.time()
    interval = beat_in_seconds
    count_array = []
    bar = 0
    while True:
        if (time.time()-tijd )>= interval:
            count = count + 1
            tijd = time.time()
            time.sleep(0.001)
            print("count=",count)
            print("bar=",bar)
            count_array.append(count)
            for event in event_list:
                if event['active'] == 1 and event['instrument'] == "kick" and event['timestamp'] == count:
                    print("kickplayed")
                    playkick.play()
                if event['active'] == 1 and event['instrument'] == "snare" and event['timestamp'] == count:
                    print("snareplayed")
                    playsnare.play()
                if event['active'] == 1 and event['instrument'] == "hihat" and event['timestamp'] == count:
                    print("hihatplayed")
                    playhihat.play()
            if count >= upper_timesig:
                #de count weer resetten dan kan ik een duidelijk begin van de maat aangeven
                count = 0
                bar = + bar + 1
            if bar > bars:
                break
