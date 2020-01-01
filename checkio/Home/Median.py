def checkio(data):
    data.sort()
    n = len(data)
    if n % 2 == 1:
        return data[n//2]
    elif n % 2 == 0:
        return (data[n//2] + data[n//2 - 1]) / 2.0
        
