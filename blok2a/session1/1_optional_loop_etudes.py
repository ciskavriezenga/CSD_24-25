"""
For- en while loop etudes
This script contains multiple etudes to practice writing forloops
and while loops to generate a specific list of indices.
"""

"""
_____________________ Example 1 _____________________
Use one forloop to generate a list with the following indices
101, 103, 105, 107, 109, 111, ..., 119
"""
l = []
for i in range(10):
    l.append(101 + (i * 2))
print(l)

"""
_____________________ Example 2 _____________________
Use a while loop to generate a list with the following indices
0, 1, 3, 6, 10, 15, 21, 28, 36, ..., 105
"""
l = []
incr = 0
current_val = 0
while incr < 15:
    current_val = current_val + incr
    l.append(current_val)
    incr = incr + 1
print(l)


"""
_____________________ Example 3 _____________________
Use a double forloop to generate a list with the following indices
0, 0, 2, 0, 2, 4, 6, 0, 2, 4, 6, 8, 10, 12, 14, 0, 2, 4, ..., 30
"""
l = []
for i in range(5):
    range_j = 2 ** i
    for j in range(range_j):
        l.append(j * 2)
print(l)



"""
_____________________ Etude 1 _____________________
Use one forloop to generate a list with the following indices
10, 13, 16, 19, 22, 25, 28, ...
"""



"""
_____________________ Etude 2 _____________________
Use one forloop to generate a list with the following indices
0, 2, 4, 6, 8, 10, 12, 14, 16, ...
"""


"""
_____________________ Etude 3 _____________________
Use one forloop to generate a list with the following indices
0, 2, 4, 6, 8, 10, 0, 2, 4, 6, 8, 10, 0, 2, ...
"""


"""
_____________________ Etude 4 _____________________
Use a double forloop to generate a list with the following indices
0, 2, 4, 6, 8, 10, 0, 2, 4, 6, 8, 10, 0, 2, ... # repeat sublist n times
"""


"""
_____________________ Etude 5 _____________________
Use while loop to generate a list with the following indices.
tip: use a multiplication of -1 at certain moments
0, 2, 4, 6, 8, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 8, ... # repeat sublist n times
"""
