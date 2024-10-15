"""

TODO
• What might be a better name for event?
• which checks are redundant?
• If nD refers the duration of a note, then what is confusing about:
    event[0].get('timestamp')*nD
"""


while len(event):
    t = time.time() - t0
    if (len(event)> 0):
        if (len(event) > 0 and t >= (event[0].get('timestamp')*nD) and event[0].get('instrument') == 'hihat'):
            noteEvent({
                'instrument':'hihat'
            })
            event.pop(0)
        if (len(event) > 0 and t >= (event[0].get('timestamp')*nD) and event[0].get('instrument') == 'kick'):
            noteEvent({
                'instrument':'kick'
            })
            event.pop(0)
        if (len(event) > 0 and t >= (event[0].get('timestamp')*nD) and event[0].get('instrument') == 'snare'):
            noteEvent({
                'instrument':'snare'
            })
            event.pop(0)
        time.sleep(0.01)
    else:
        break
time.sleep(0.5)
