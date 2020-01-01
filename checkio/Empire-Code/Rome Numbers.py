def roman(data):
    roman_list = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
    number_list = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]

    result = ''
    while data > 0:
        for i in range(0, len(roman_list)):
            if data - number_list[i] >= 0:
                data -= number_list[i]
                result += roman_list[i]
                break
        
    return result


if __name__ == '__main__':
    # These "asserts" using only for self-checking and not necessary for auto-testing
    assert roman(6) == 'VI', '6'
    assert roman(76) == 'LXXVI', '76'
    assert roman(499) == 'CDXCIX', '499'
    assert roman(3888) == 'MMMDCCCLXXXVIII', '3888'
    print("Earn cool rewards by using the 'Check' button!")
