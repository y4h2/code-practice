def checkio(text, word):
    word = word.lower()
    text = text.lower()
    text = text.replace(' ', '')
    text = text.split('\n')
    length = len(word)
    for col in range(len(text)):
        line = text[col]
        for i in range(len(line)):
            if line[i: i + length] == word:
                return [col + 1, i + 1, col + 1, i + length]
    #before using zip() to transpose a matrix, have to make sure all cols and rows are the same 
    longestline = max(map(len, text))
    for i in range(len(text)):
        text[i] += ' ' * (longestline - len(text[i]))
    text = zip(*text)
    
    for i in range(len(text)):
        text[i] = ''.join(list(text[i]))
    for col in range(len(text)):
        line = text[col]
        for i in range(len(line)):
            if line[i: i + length] == word:
                return [i + 1, col + 1, i + length, col + 1]
                
                
                
  #better solution, using find() and enumerate() method
  def CipherText(text):
    return ''.join([j.lower()
                    for i in text for j in i if j != ' ']).split('\n')


def checkio(text, word):
    CipheredText = CipherText(text)
    LongestLine = max(map(len, CipheredText))
    for i in range(len(CipheredText)):
        CipheredText[i] += ' ' * (LongestLine - len(CipheredText[i]))
    RowStart, RowEnd, ColStart, ColEnd = 0, 0, 0, 0
    # in rows
    for i, j in enumerate(CipheredText):
        index = j.find(word)
        if index != -1:
            RowStart = RowEnd = i + 1
            ColStart = index + 1
            ColEnd = index + len(word)
    if RowStart != 0:
        return [RowStart, ColStart, RowEnd, ColEnd]
    # in cols
    CipheredText = zip(*CipheredText[::])
    for i in range(len(CipheredText)):
        CipheredText[i] = ''.join(list(CipheredText[i]))
    for i, j in enumerate(CipheredText):
        index = j.find(word)
        if index != -1:
            ColStart = ColEnd = i + 1
            RowStart = index + 1
            RowEnd = index + len(word)
