import math

import standDev, random, time


def calculate_standDev(l):
    start = time.time()

    aver = sum(l) / len(l)

    sum_disp = 0

    for i in l:
        sum_disp += (i - aver) ** 2

    sum_disp /= len(l)

    stand_dev = math.sqrt(sum_disp)

    end = time.time()
    time_taken = end - start

    return stand_dev, time_taken

l = [random.randint(1, 10_000) for i in range(100_000_000)]

input("calculate")
# print(standDev.calculate(l))
print(calculate_standDev(l))
