def checkio(text):
    result = []
    text = text.lower()
    for letter in text:
        if letter >= 'a' and letter <= 'z':
            result.append((letter, text.count(letter)))
    result = sorted(result, key=lambda x: (-x[1], x[0]))
    return result[0][0]
