#for bool logical operation, should transfer the vairable to the bool type first

OPERATION_NAMES = ("conjunction", "disjunction", "implication", "exclusive", "equivalence")


def boolean(x, y, operation):
    x, y = bool(x), bool(y)
    if operation == OPERATION_NAMES[0]:
        return x and y
    elif operation == OPERATION_NAMES[1]:
        return x or y
    elif operation == OPERATION_NAMES[2]:
        return (not x) or y
    elif operation == OPERATION_NAMES[3]:
        return x != y
    elif operation == OPERATION_NAMES[4]:
        return x == y


if __name__ == '__main__':
    # These "asserts" using only for self-checking and not necessary for auto-testing
    assert boolean(1, 0, "conjunction") == 0, "and"
    assert boolean(1, 0, "disjunction") == 1, "or"
    assert boolean(1, 1, "implication") == 1, "material"
    assert boolean(0, 1, "exclusive") == 1, "xor"
    assert boolean(0, 1, "equivalence") == 0, "same?"

    print("All done? Earn rewards by using the 'Check' button!")
