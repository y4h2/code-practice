VOWELS = "AEIOUY"
CONSONANTS = "BCDFGHJKLMNPQRSTVWXZ"
import string

def checkio(text):
    cnt = 0
    exclude = set(string.punctuation)
    for c in exclude:
        if c in text:
            text = text.replace(c, ' ')
    #text = ''.join(ch for ch in text if ch not in exclude).upper()
    text_list = text.upper().split()
    print text_list
    for word in text_list:
        print word
        if len(word) == 1:
            continue
        if word[0] in VOWELS:
            flag = True
            for letter in word[1:]:
                print letter, flag
                if flag and letter in CONSONANTS:
                    flag = False
                elif not flag and letter in VOWELS:
                    flag = True
                else:
                    cnt -= 1
                    break
            cnt += 1
        elif word[0] in CONSONANTS:
            flag = True
            for letter in word[1:]:
                if flag and letter in VOWELS:
                    flag = False
                elif not flag and letter in CONSONANTS:
                    flag = True
                else:
                    cnt -= 1
                    break
            cnt += 1
        else:
            continue
    print cnt
    return cnt

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio(u"My name is ...") == 3, "All words are striped"
    assert checkio(u"Hello world") == 0, "No one"
    assert checkio(u"A quantity of striped words.") == 1, "Only of"
    assert checkio(u"Dog,cat,mouse,bird.Human.") == 3, "Dog, cat and human"
    
#shorter solution
#use subset
VOWELS = "AEIOUY"
CONSONANTS = "BCDFGHJKLMNPQRSTVWXZ"
import string

def checkio(text):
    cnt = 0
    for c in string.punctuation:
        if c in text:
            text = text.replace(c, ' ')
    #text = ''.join(ch for ch in text if ch not in exclude).upper()
    text_list = text.upper().split()
    for token in text_list:
        if len(token) == 1:
            continue
        outer = set(token[::2])
        inner = set(token[1::2])
        if (outer.issubset(VOWELS) and inner.issubset(CONSONANTS)) or \
            (outer.issubset(CONSONANTS) and inner.issubset(VOWELS)):
            cnt += 1
    return cnt

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio(u"My name is ...") == 3, "All words are striped"
    assert checkio(u"Hello world") == 0, "No one"
    assert checkio(u"A quantity of striped words.") == 1, "Only of"
    assert checkio(u"Dog,cat,mouse,bird.Human.") == 3, "Dog, cat and human"

