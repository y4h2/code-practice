def checkio(number):
    minute = 0
    pigeons = 0
    fed_pigeons = 0
    food = number
    
    while True:
        minute += 1
        old_pigeons = pigeons
        pigeons += minute
        
        if food < pigeons:
            remain_food = food - old_pigeons
            if remain_food > 0:
                fed_pigeons += remain_food
            break
        else:
            food -= pigeons
            fed_pigeons = pigeons
            
    return fed_pigeons



if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio(1) == 1, "1st example"
    assert checkio(2) == 1, "2nd example"
    assert checkio(5) == 3, "3rd example"
    assert checkio(10) == 6, "4th example"
