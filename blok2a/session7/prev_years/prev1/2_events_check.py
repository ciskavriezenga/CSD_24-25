
"""
NOTES:
• greg variable = number of beats in a bar

TODO 
• SEARCH FOR:
    • unnecessary forloop & checks
    • what is 'targetTime', does that actually correspond to a 'sample to play'?
        imagine 'an extreme setting': many sixteenth notes per bar &
        many events at the the same moment.
• 


"""

#_________playing___________

for repeats in range(4): #could be replaced by a while loop for infinite repeats
    #counter
    time_zero = time.time()
    #amount of steps
    for index in range(greg):
        print(index)

        #on button for while loop
        running = True
        #targetTime is where the next hit should be. We use the sixTeenths[]
        targetTime = allSteps[index]
        while running:
            #what is the time now
            currentTime = time.time() - time_zero
            #has the clock hit the targetTime?
            if currentTime >= targetTime:
                for event in events:
                    if event['timeStamp'] == allSteps[index]:
                            playEvent(event)
                #turn off the while loop to go to the next step
                running = False
            else:
                time.sleep(0.001)





"""
TODO
• SEARCH FOR:
    • the line that introduces an offset of 1 sixteenth
"""

def calculateSteps(amountSixTeenthNote, sixTeenthStep):
    for i in range(amountSixTeenthNote):
        allSteps.append((i+1) * sixTeenthStep)
    allSteps.pop() #remove the last step
