
"""

TODO
• How can 'caching' of which value improve the readability?
• what is allSampleDict?

"""



def sample_player(self):
    self.timeZero = time.time()
    self.i = 0
    while True:
        self.timeCurrent = time.time() - self.timeZero
        if(self.timeCurrent >= float(allSampleDict[instrumentnameChoiceAnswer]['timeStamps'][self.i])):
            allSampleDict[instrumentnameChoiceAnswer]['filename'].play()
            self.i += 1
        if self.i == allSampleDict[instrumentnameChoiceAnswer]['numberSteps'] and allSampleDict[instrumentnameChoiceAnswer]['loop'] == 1:
            self.i = 0
            self.timeZero = time.time()
        time.sleep(0.0001)
