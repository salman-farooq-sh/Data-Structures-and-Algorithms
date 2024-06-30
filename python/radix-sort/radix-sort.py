import random


def counting_sort(iterable, key):
    max_key = key(max(iterable, key=key))
    min_key = key(min(iterable, key=key))
    scaling_factor = -min_key

    count = [0] * (max_key - min_key + 1)
    for element in iterable:
        count[key(element) + scaling_factor] += 1

    for i in range(1, len(count)):
        count[i] += count[i - 1]

    output = [None] * len(iterable)
    for element in reversed(iterable):
        output[count[key(element) + scaling_factor] - 1] = element
        count[key(element) + scaling_factor] -= 1

    return output


# calling this without passing value for base will set base = len(number_list)
def radix_sort(number_list, base=0):
    upper_widest = len(str(abs(max(number_list))))
    lower_widest = len(str(abs(min(number_list))))  # to handle negative ...
    widest = max(lower_widest, upper_widest)        # ... numbers in the list

    if base == 0:
        base = len(number_list)  # asymptotically, this will give the best performance

    for n in range(1, widest + 1):
        number_list = counting_sort(number_list, key=nthdigit(n, base))

    return number_list


def is_sorted(iterable):
    return all(iterable[i] <= iterable[i + 1] for i in range(len(iterable) - 1))


# returns a function which takes a number
# as an input and returns the nth digit,
# from the right side, of that number in
# the specified base
def nthdigit(n, base=10):
    return lambda num: custom_remainder(int(num / base ** (n - 1)), base)


def custom_remainder(a, b):
    return a % b if a > 0 else -(-a % b)


# driver code:
for i in range(10000):
    test_list = [random.randint(-100, 100) for _ in range(50)]
    output_list = radix_sort(test_list)

    if not is_sorted(output_list):
        print("Failure:-")
        print("input: ", test_list)
        print("output: ", output_list, '\n')