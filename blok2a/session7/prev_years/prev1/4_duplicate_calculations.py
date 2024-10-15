
"""
TODO
• Find the duplicate code
    HINT:
    there are 10 lines that can be replaced with 1 line by using a simple
        topMaat * 8 / (botMaat / 2)
    calculation
"""

#change maatsoort
def changeMaat(sixTeenthStep):
    topMaat = int(input("Enter topMaat: ")) # num pulses, 7/8--> 7
    botMaat = int(input("Enter botMaat: ")) # pulses length , 7/8 --> 8
    #resetevents because it won't work anymore after redoing this.
    events = []
#checking if the botMaat makes sense
    # botmaat = 16
    amountSixTeenthNote = topMaat *  16 / botMaat

    # botmaat = 8
    amountSixTeenthNote = topMaat *  16 / botmaat

    if botMaat == 2:
        amountSixTeenthNote = topMaat * 8
    elif botMaat == 4:
        amountSixTeenthNote = topMaat * 4
    elif botMaat == 8:
        amountSixTeenthNote = topMaat * 2
    elif botMaat == 16:
        amountSixTeenthNote = topMaat
    elif botMaat == 32:
        amountSixTeenthNote = topMaat / 2

    else:
        amountSixTeenthNote = 4
        print("Maatsoort Error - Maatsoort now: ", topMaat, " / 4 ")
    return amountSixTeenthNote
