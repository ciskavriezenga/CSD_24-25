""""
SESSION 7
SNIPPETS - EXAMPLES OF DUPLICATE CODE, 'BAD' PRACTICE, COMMENTS ETC.
"""

# SIMPLIFY
# ===== EXAMPLE 1 =======
# code below could be replaced by using a list as a sort of look up table:
"""
kicks_blueprint = [[3], [4], [4, 1], [4, 2], [7]]
if meter >= 3 and meter <= 7: 
    # shift meter value to index, meter 3 starts at index 0
    kicks.append(kicks_blueprint[meter - 3]) 
else: 
    kicks.append(-5)
"""


def generate_kick_snare(meter):
    meter2 = meter # second meter for generating the snare

    kicks = []
    snares = []

    # generate kicks
    while True:
        if meter == 7:
            kicks.append(7)
            break
        elif meter == 4:
            kicks.append(4)
            break
        elif meter == 5:
            kicks.append(4)
            kicks.append(1)
            break
        elif meter == 6:
            kicks.append(4)
            kicks.append(2)
            break
        elif meter == 3:
            kicks.append(3)
            break
        else:
            kicks.append(5)
            meter = meter-5

    random.shuffle(kicks) # shuffles kicks


