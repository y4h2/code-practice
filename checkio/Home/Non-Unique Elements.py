
def checkio(data):
    #Your code here
    #It's main function. Don't remove this function
    #It's used for auto-testing and must return a result for check.  
    l = []
    for number in data:
        if data.count(number) > 1:
            l.append(number)
    return l
