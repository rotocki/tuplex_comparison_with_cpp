from multiprocessing import Pool
from time import perf_counter

from tuplex import Context


def count_primes(up_to):
    count = 0
    for number in range(2, up_to + 1):
        for divisor in range(2, number):
            if number % divisor == 0:
                break
        else:
            count += 1
    return count


values = [value * 1_000 for value in [10, 20, 30, 40]]

loop_start = perf_counter()
loop_result = [count_primes(value) for value in values]
loop_end = perf_counter()
print(f"Single for-loop elapsed: {loop_end - loop_start}. Result: {loop_result}")

with Pool(4) as pool:
    mp_start = perf_counter()
    mp_result = pool.map(count_primes, values)
    mp_end = perf_counter()
    print(f"Multiprocessing elapsed: {mp_end - mp_start}. Result: {mp_result}")

c = Context()
print(c.parallelize(values).map(count_primes).collect())
