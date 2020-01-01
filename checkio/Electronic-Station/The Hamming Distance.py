def checkio(n, m):
    cnt = 0
    bin_n = bin(n)[2:]
    bin_m = bin(m)[2:]
    if len(bin_n) > len(bin_m):
        bin_m = bin_m.zfill(len(bin_n))
    elif len(bin_m) > len(bin_n):
        bin_n = bin_n.zfill(len(bin_m))
        
    for i in range(0, len(bin_m)):
        if bin_n[i] == bin_m[i]:
            continue
        else:
            cnt += 1
    
    return cnt

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio(117, 17) == 3, "First example"
    assert checkio(1, 2) == 2, "Second example"
    assert checkio(16, 15) == 5, "Third example"
