# Euclidean example, with rotation

def gen_seq(num_pulses, num_notes, num_rotations):
    # calculate duration of a note, expressed in 16th
    dur = int(num_pulses / num_notes)
    # fill list num_notes times with the duration value
    sequence = [dur] * num_notes

    # calculate the rest value and distribute these amongst the stored durations
    rest_value = num_pulses - (num_notes * dur)
    for i in range(rest_value):
        sequence[i] += 1

    # rotate the sequence
    sequence = rotate(sequence, num_rotations)
    return sequence

def rotate(l, num_rotations):
    """
    Rotates the presented sequence.
    E.g.  rotate([4, 4, 3, 3, 3], 2`) --> [3, 3, 4, 4, 3]

    NOTE: What if you offset notes based on a given pulse ofset instead?
    E.g. offset([4, 4, 3, 3, 3], 2) --> [2, 4, 4, 3, 3, 1]
    The above example results in an additional note. Maybe add a rest instead?

    l: list containing sequence expressed in note durations
    num_rotations: number of pulses to rotate the sequence
    """
    if(num_rotations < len(l)):
        l = l[num_rotations:] + l[:num_rotations]
    else:
        print("Function rotate: num_rotations exceeds the length of l.")
    return l


"""
Generate sequences based on user input.
This example uses a set to store the generate sequences.
A set is great data structure to store sequences and check if a new sequence
equals a stored sequence.
This funcionality could be useful to prevent generating the same rhythm twice.
"""
sequences = set()
continue_generation = True

#
while continue_generation:
    num_pulses = int(input("Please enter the number of pulses: "))
    num_notes = int(input("Please enter the number of notes: "))
    num_rotations = int(input("Please enter the rotation value: "))

    seq = gen_seq(num_pulses, num_notes, num_rotations)
    print("The generated sequences: ", seq)

    if(tuple(seq) in sequences):
        print("***** Our set already contains this sequence! *****")
    else:
        # if new sequence is not in sequences already, add it
        sequences.add(tuple(seq))
    print("Our sequences set contains: ", sequences)

    continue_generation = input("do you want to continue? Press y and enter: ") == 'y'
