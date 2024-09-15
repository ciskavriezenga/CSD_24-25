import time

# Using time.sleep in a forloop does not guarantee exactly 1 sec.
t = time.time()

"""
for i in range(10):
    print("delta t:", time.time() - t)
    t = time.time()
    time.sleep(1)
"""
"""
# This results in a cumulative error
zero_time = time.time()

for i in range(10):
    time.sleep(1)
    print("delta t:", time.time()-zero_time)
"""

# differences between short and long time.sleep durations

test_durations = [0.1, 1.0, 10.0, 100.0]
means = []


for index, dur in enumerate(test_durations):
    sum = 0
    num_tests = 10
    print("Iteration number", index, ", duration:", dur)
    for i in range(num_tests):
        t = time.time()
        time.sleep(dur)
        deviation = time.time() - t - dur
        print("time deviation:", deviation)
        sum += deviation

    means.append(sum / num_tests)
    # reset sum for next test iteration
    sum = 0

for index, mean in enumerate(means):
    print("\nMean time deviation test", index)
    print("Duration:", test_durations[index])
    print("Mean deviation:", mean)


"""
Mean time deviation test 0
Duration: 0.1
Mean deviation: 0.0011663436889648381

Mean time deviation test 1
Duration: 1.0
Mean deviation: 0.0029978275299072264

Mean time deviation test 2
Duration: 10.0
Mean deviation: 0.00169827938079834

Mean time deviation test 3
Duration: 100.0
Mean deviation: 0.0016396284103393556
"""