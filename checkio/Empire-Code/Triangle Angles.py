# use cosine formula
# the result should be sorted
# have to examine whether three sides can be a triangle

def angles(a, b, c):
    from math import degrees, acos
    if 2 * max(a, b, c) >= a + b + c:
        return [0, 0, 0]
    else:
        return sorted([round(degrees(acos((b*b + c*c - a*a) / (2*b*c)))), round(degrees(acos((+ c*c + a*a - b*b ) / (2*a*c)))), round(degrees(acos((b*b + a*a - c*c) / (2*a*b))))])


if __name__ == '__main__':
    # These "asserts" using only for self-checking and not necessary for auto-testing
    assert angles(4, 4, 4) == [60, 60, 60], "All sides are equal"
    assert angles(3, 4, 5) == [37, 53, 90], "Egyptian triangle"
    assert angles(2, 2, 5) == [0, 0, 0], "It's can not be a triangle"

    print("Code's finished? Earn rewards by clicking 'Check' to review your tests!")
