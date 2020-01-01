TENS = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
              "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
OTHER_TENS = ["", "ten", "twenty", "thirty", "forty", "fifty",
              "sixty", "seventy", "eighty", "ninety"]
HUNDRED = "hundred"
THOUSAND = "thousand"

def number_less_1000(number):
    result = ""
    if number // 100 != 0:
        result += TENS[number // 100] + ' ' + HUNDRED + ' '
        number -= number // 100 * 100
    if number < 20:
        result += TENS[number]
    else:
        result += OTHER_TENS[number // 10] + ' ' + TENS[number % 10]
        
    return result
    
def tell_number(number):
    result = ""
    if number == 0:
        return 'zero'
    if number < 0:
        result += 'minus' + ' '
        number = -number
    if number // 1000 != 0:
        temp = number // 1000
        number = number % 1000
        result += number_less_1000(temp)
        result += ' ' + THOUSAND + ' '
    result += number_less_1000(number)
    if result[-1] == ' ':
        result = result[:-1]
    return result



if __name__ == '__main__':
    # These "asserts" using only for self-checking and not necessary for auto-testing
    # Rank 1
    assert tell_number(4) == 'four', "1st example"
    assert tell_number(133) == 'one hundred thirty three', "2nd example"
    assert tell_number(12) == 'twelve', "3rd example"
    assert tell_number(101) == 'one hundred one', "4th example"
    assert tell_number(212) == 'two hundred twelve', "5th example"
    assert tell_number(40) == 'forty', "6th example"
    assert not tell_number(212).endswith(' '), "Dont forget strip whitespaces at the end of string"

    # Rank 2
    assert tell_number(-133) == 'minus one hundred thirty three', "Minus"
    assert tell_number(0) == 'zero', "Zero"

    # Rank 3
    assert tell_number(42000) == 'forty two thousand', "42 many"
    assert (tell_number(-999999) ==
            "minus nine hundred ninety nine thousand nine hundred ninety nine"), "Abyss"

    print("Earn cool rewards by using the 'Check' button!")
