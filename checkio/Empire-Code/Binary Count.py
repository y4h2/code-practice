def count_units(number):
    cnt = 0

    while number > 0:
        if number % 2 == 1:
            cnt += 1
        number /= 2
        number = int(number)
    return cnt

if __name__ == '__main__':
    # These "asserts" using only for self-checking and not necessary for auto-testing
    assert count_units(4) == 1
    assert count_units(15) == 4
    assert count_units(1) == 1
    assert count_units(1022) == 9

    print("Use 'Check' to earn sweet rewards!")
