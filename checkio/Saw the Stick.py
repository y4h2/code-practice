from math import sqrt
​
def triangular_number(i):
    return i * (i + 1) / 2
    
​
def checkio(number):
    n = int(sqrt(number * 2))
    number_list = []
    for i in range(1,n + 1):
        if triangular_number(i) < number:
            number_list.append(triangular_number(i))
    length = len(number_list)
    while length > 1:
        for i in range(len(number_list) - length + 1):
            if sum(number_list[i:i + length]) == number:
                return number_list[i:i + length]
        length -= 1
    return []
