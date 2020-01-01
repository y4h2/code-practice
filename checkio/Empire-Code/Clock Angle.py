'''
Because minute point will influence the hour point
thus the degree of m should be 5.5
'''

def clock_angle(time):
    from cmath import rect, phase
    from math import radians, degrees
    h, m = map(int, time.split(":"))
    return round(degrees(abs(phase(rect(1, radians(30 * h - 5.5 * m))))), 1)

if __name__ == '__main__':
    # These "asserts" using only for self-checking and not necessary for auto-testing
    assert clock_angle("02:30") == 105, "02:30"
    assert clock_angle("13:42") == 159, "13:42"
    assert clock_angle("01:42") == 159, "01:42"
    assert clock_angle("01:43") == 153.5, "01:43"
    assert clock_angle("00:00") == 0, "Zero"
    assert clock_angle("12:01") == 5.5, "Little later"
    assert clock_angle("18:00") == 180, "Opposite"

    print("Now that you're finished, hit the 'Check' button to review your code and earn sweet rewards!")
