"""
In this example the usage of functions to generate a list with dictionaries is
demonstrated.
"""

import random

"""
 _____ globals used to find the correct chords _____
NOTE: the use of classes could probably prevent the usage of globals
This would result in nicer code. It would e.g. allow to us to pass
scale objects for which you can ask the corresponding triads as following:
    a_scale.triads()

TODO - add functionaly to also use 'flat' tones instead of always sharp
"""
tones = ['a', 'a#', 'b', 'c', 'c#', 'd', 'd#', 'e', 'f', 'f#', 'g', 'g#']

# the distances between the notes in a scale
scale_halftone_dist = {
    'maj' : [2, 2, 1, 2, 2, 2, 1],
    # NOTE: ignored the possibility to heighten 7th note in a minor scale
    'min' : [2, 1, 2, 2, 1, 2, 2]
}

# the distances between the notes in a scale
scale_triad_types = {
    # the triad types in a scale
    'maj' : ['maj', 'min', 'min', 'maj', 'maj', 'min', 'dim'],
    # NOTE: based on the heightened 7th note for chord V
    'min' : ['min', 'dim', 'maj', 'min', 'maj', 'maj', 'maj']
}

def triads_for_scale(scale):
    """
    Returns the triad at the index of a given scale.

    parameter scale: the scale dictionary, for now either minor or minor, with
        dictionary keys 'type' and 'key'
        NOTE: for now, only sharp keys are allowed

    parameter index: the index of the triad to return

    scale type: dictionary
    index type: int

    return: a list with triads (type = string)
    """
    # list to store the triads in the given scale
    triads = []

    print("Retrieving the triads for the scale", scale['key'], scale['type'])

    # find the index of the note corresponding to the key in the scale
    tone_index = tones.index(scale['key'])
    halftone_dist = scale_halftone_dist[scale['type']]
    triad_types = scale_triad_types[scale['type']]

    for i in range(7):
        # if tone index exceeds length tones --> wrap
        if tone_index >= len(tones):
            tone_index = tone_index - len(tones)
        tone = tones[tone_index]
        # generate triad string and append to triads list
        triad_type = triad_types[i]
        triad = tone + "-" + triad_type
        print("triad at index", i, ":", triad)
        triads.append(triad)
        # select the next tone, by incrementing the tone index
        tone_index = tone_index + halftone_dist[i]

    return triads


def gen_random_progression(scale, num_measures):
    """
    Returns a chord progression in the given key with the given number
    of measures.

    parameter scale: the scale dictionary, for now either minor or minor, with
        dictionary keys 'type' and 'key'
        NOTE: for now, only sharp keys are allowed

    parameter num_measures: the number of measures in the progression

    scale type: dictionary
    num_measures type: int

    returns: list with triad quarternote position
        (dictionaries with 'triad' and 'qnote_pos' keys)
    """

    # TODO - add validation of input
    progression = []

    # retrieve the available chords according to given scale
    chords = triads_for_scale(scale)

    # we also allow for chords with a duration of a half measures
    # NOTE: currently we assume a 4/4 measure
    allowed_qnote_dur = [2, 4]
    total_qnote_dur = num_measures * 4
    # start with timestamp at position 0 in the progression and continue
    # to fill the progression until we reach the total duration
    qnote_pos = 0

    while qnote_pos < total_qnote_dur:
        # generate timestamp dictionary with a random triad and random duration
        triad_ts = {
            'triad': random.choice(chords),
            'qnote_pos': qnote_pos
        }
        progression.append(triad_ts)
        # increment timestamp with random duration
        qnote_pos = qnote_pos + random.choice(allowed_qnote_dur)
    return progression


# demonstrate the usage of these functions
scale = {
    'key': 'c',
    'type': 'maj'
}

num_measures = 4

progression = gen_random_progression(scale, num_measures)

print(progression)
