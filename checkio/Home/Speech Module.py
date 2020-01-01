FIRST_TEN = ["one", "two", "three", "four", "five", "six", "seven",
             "eight", "nine"]
SECOND_TEN = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
              "sixteen", "seventeen", "eighteen", "nineteen"]
OTHER_TENS = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy",
              "eighty", "ninety"]
HUNDRED = "hundred"
​
​
def checkio(number):
    first = number % 10
    second = number // 10 % 10
    third = number // 100 % 10
    result = []
    if third != 0:
        result.append( FIRST_TEN[third - 1])
        result.append(HUNDRED)
    if second != 0:
        if second == 1:
            result.append(SECOND_TEN[first])
            return ' '.join(result)
        else:
            result.append(OTHER_TENS[second - 2])
    if first != 0:
        result.append(FIRST_TEN[first - 1])
    return ' '.join(result)
