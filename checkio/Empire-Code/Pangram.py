#remove punctuation and space
from string import punctuation
def check_pangram(text):
    exclude = set(punctuation)
    exclude.add(' ')
    text = ''.join(ch for ch in text if ch not in exclude).lower()
    text_set = set(text)
 
    if len(text_set) == 26:
        return True
    else:
        return False

if __name__ == '__main__':
    # These "asserts" using only for self-checking and not necessary for auto-testing
    assert check_pangram("The quick brown fox jumps over the lazy dog."), "brown fox"
    assert not check_pangram("ABCDEF"), "ABC"
    assert check_pangram("Bored? Craving a pub quiz fix? Why, just come to the Royal Oak!"), "Bored?"

    print("All done? Earn rewards by using the 'Check' button!")
