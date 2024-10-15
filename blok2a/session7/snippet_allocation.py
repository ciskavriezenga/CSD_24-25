""""
SESSION 7
SNIPPETS - EXAMPLES OF DUPLICATE CODE, 'BAD' PRACTICE, COMMENTS ETC.
"""


# ===== EXAMPLE 1 =======

# a wave object is allocated in playback loop
# improvemnt: allocate wave object outside the forloop just once
for i in range(len(sequence)*nLoops):
    print('boom')
    wave_obj = sa.WaveObject.from_wave_file("/Users/x/Documents/Spaces/Resources/Sounds/Drums/Analog/Kick/MFB_Kick/wa_tanzbar_kick_17.wav") # copy your path to a wav file here
    play_obj = wave_obj.play()
    sleep(60/bpm*sequence[i%len(sequence)])
play_obj.wait_done()
print("Done")



# ===== EXAMPLE 2 =======
def defineEvents():
    hihat = sa.WaveObject.from_wave_file(
        "/Users/x/HKU/Jaar2/CSD2/CSD_23-24/blok2a/assets/hihat.wav"
        )
    snare = sa.WaveObject.from_wave_file(
        "/Users/x/HKU/Jaar2/CSD2/CSD_23-24/blok2a/assets/snare.wav"
    )
    kick = sa.WaveObject.from_wave_file(
        "/Users/x/HKU/Jaar2/CSD2/CSD_23-24/blok2a/assets/kick.wav"
    )

    hihat_event = {
        "noteDurations": [],
        "timestamps16th": [0.0],
        "timestampsMs": [],
        "instrumentname": "hihat",
        "instrument": hihat,
        "velocity": 82,
        "duration": 100,
    }

    snare_event = {
        "noteDurations": [],
        "timestamps16th": [0.0],
        "timestampsMs": [],
        "instrumentname": "snare",
        "instrument": snare,
        "velocity": 82,
        "duration": 100,
    }

    kick_event = {
        "noteDurations": [],
        "timestamps16th": [0.0],
        "timestampsMs": [],
        "instrumentname": "kick",
        "instrument": kick,
        "velocity": 82,
        "duration": 100,
    }

    # stores all events in list
    events = [kick_event, hihat_event, snare_event]

    return events

