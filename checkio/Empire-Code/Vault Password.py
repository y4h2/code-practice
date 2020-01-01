def golf(p):
    return p.lower() != p and p.upper() != p and not p.isalpha() and len(p) >= 10

# if __name__ == '__main__':
#     # These "asserts" using only for self-checking and not necessary for auto-testing
#     golf('A1213pokl') == False
#     golf('bAse730onE') == True
#     golf('asasasasasasasaas') == False
#     golf('QWERTYqwerty') == False
#     golf('123456123456') == False
#     golf('QwErTy911poqqqq') == True
#     print (golf('fsDSkjSDDSJhjhjd'))
#     print("Use 'Check' to earn sweet rewards!")
