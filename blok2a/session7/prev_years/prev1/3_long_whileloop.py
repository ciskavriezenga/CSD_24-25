
"""
NOTES:


TODO
• SEARCH FOR:
    • which parts of the inner while loop should actually be in the while
        and which not?
• 


"""
while True:


    counter = 0
    while counter < 4:
        # nu is de tijd die begint bij 0 oplopend
        nu = time.time() - tijdBegin

        for event in events:
            # als het geluid van de kick matcht met de timestamp op dat moment speelt er een kick en zo voort
            if (nu >= event['timestamps']):
                instrument = event['instrument']
                samples[instrument]

















                if i["instrument"] == 'kick':
                    kick.play()
                    print("                      |          ʕ•ᴥ•ʔ")
                if i["instrument"] == 'snare':
                    snare.play()
                    print("                      |                    (▀̿Ĺ̯▀̿ ̿)")
                if i["instrument"] == 'hat':
                    hat.play()
                    print("                      |                             (͡• ͜ʖ ͡•)")


                if i["instrument"] == 'bongo1':
                    bongo1.play()
                    print("         (；☉_☉)")
                if i["instrument"] == 'bongo2':
                    bongo2.play()
                    print("(☉_☉ ；)")


                # elke keer als er een geluid is gespeeld moet er 1 geluid weg
                alleStamps.remove(i)

                # elke keer als de lijst leeg is zal er
                # of een nieuwe zelfde lijst komen tenzij
                # de loop op is (dus al hoevaakLoop) is geweest,
                # in dat geval zal hij vragen "wil je de zelfde loop of een ander?"
                # dan zal dus de lijst opnieuw met de zelfde lijst gevult worden of met een nieuwe
                if alleStamps == []:
                    counter += 1
                    print(counter)
                    if counter < hoevaakLoop:
                        print("--------------------------------------------------------------------------")
                        print("")
                        print("༼ ºل͟º ༼ ºل͟º ༼ ºل͟º ༽ ºل͟º ༽ ºل͟º ༽   ༼ ºل͟º ༼ ºل͟º ༼ ºل͟º ༽ ºل͟º ༽ ºل͟º ༽")
                        print("--------------------------------------------------------------------------")
                        tijdBegin = time.time()
                        nu = time.time() - tijdBegin
                        alleStamps = copieVstampels
                        copieVstampels = alleStamps.copy()

                    else:
                        print("-------------------------------------")
                        print("Wil je nog een keer de zelfde loop?")
                        print("Zelfde Loop == 0")
                        print("Nieuwe Loop == 1")
                        print("-------------------------------------")
                        opnieuw = int(input())
                        if opnieuw == 0:
                            # speel de oude lijst weer af en begin  weer bij 0
                            tijdBegin = time.time()
                            nu = time.time() - tijdBegin
                            alleStamps = copieVstampels
                            copieVstampels = alleStamps.copy()

                        if opnieuw == 1:
                            # maak een nieuwe lijst met timestamps en begin weer bij 0
                            copieVstampels.clear()
                            alleStamps.clear()

                            bijElkaar()
                            copieVstampels = alleStamps.copy()
                            tijdBegin = time.time()
                            nu = time.time() - tijdBegin
                            alleStamps = copieVstampels
                            copieVstampels = alleStamps.copy()
