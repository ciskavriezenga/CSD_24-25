
# NOTE: hardcoded dictionaries, for the sake of the example
#   but is bad practice ...
kick_events = [{
    'instrument': 'kick',
    'timestamp': 0.0
},
{
    'instrument': 'kick',
    'timestamp': 9
},
{
    'instrument': 'kick',
    'timestamp': 0.6
},

]

snare_events = [{
    'instrument': 'snare',
    'timestamp': 10
},
{
    'instrument': 'snare',
    'timestamp': 0.8
},
{
    'instrument': 'snare',
    'timestamp': 0.7
},
]

events = kick_events + snare_events


def get_timestamp(events):
    return events.get('timestamp')

events.sort(key =get_timestamp)
print("\n\n\n" ,events, "\n\n\n" )
