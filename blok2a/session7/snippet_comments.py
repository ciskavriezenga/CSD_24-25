""""
SESSION 7
SNIPPETS - EXAMPLES OF DUPLICATE CODE, 'BAD' PRACTICE, COMMENTS ETC.
"""

# COMMENTS
# ===== EXAMPLE 1 =======

def iterateThroughTimestamps(events, all_timestamps):
    # stores current time in ms
    current_time = time.time()

    # Initialize a dictionary to keep track of played events
    played_events = {}

# ====== COMMENTS =====
# COMMENTS --> why 'time to sleep'? It is clear if you continue to read the code, but not instantly clear.
# therefore a comment would save time by clarifying the usage of time_to_sleep

    # Iterate through each timestamp and calculate time to sleep
    for timestamp in all_timestamps:
        time_to_sleep = timestamp - current_time

        if time_to_sleep > 0:
            time.sleep(time_to_sleep)

        # Iterate through each event and check if the current timestamp is present in the timestamps list
        for event in events:
            if timestamp in event["timestampsMs"]:
                event_name = event["instrumentname"]

                # Check if this event has already been played at this timestamp
                if event_name not in played_events or timestamp not in played_events[event_name]:
                    print(f"Current Time: {timestamp} seconds, Instrument: {event_name}")
                    event["instrument"].play()

                    # Mark the event as played at this timestamp
                    if event_name not in played_events:
                        played_events[event_name] = set()
                    played_events[event_name].add(timestamp)

        # Update current_time to the current timestamp
        current_time = timestamp

    time.sleep(1)


# ====== COMMENTS =====
# 'grey area' - as in, probably the opions will differ regarding the example below
# it is not immediately clear that track is a reference to (probably?) a list,
# it would be good to add this in a minor comment
# personaly, a different setup would be preferable.
# I (Ciska) do not like it if a list that is managed by a sequencer can easily be altered outside the sequencer

def generate_low_pattern(sequencer, length):
    """
    Generate a kick pattern. A kick is always played on the first sixteenth of
    a measure.
    """
    audio_file = sa.WaveObject.from_wave_file("../assets/kick.wav")
    track = sequencer.add_track(length, audio_file, "kick")

    for i in range(16):
        if i == 0 or random() < 0.2:
            track.add_note(i, 1, 100)
