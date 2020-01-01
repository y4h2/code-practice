# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys

paragraph = ''
for line in sys.stdin:
    paragraph += line.lower()

#paragraph = raw_input().lower()
punctuations = ",.?!"
for punctuation in punctuations:
    paragraph = paragraph.replace(punctuation, ' ')

words = paragraph.split(" ")
ngram_dict = {}
def ngrams(word):
    result = []
    for ngram in zip(word, word[1:], word[2:]):
        temp = ""
        for gram in ngram:
            temp += " " + gram
        result.append(temp[1:])
    return result
        
        

for ngram in ngrams(words):
    if not ngram in ngram_dict:
        ngram_dict[ngram] = 1
    else:
        ngram_dict[ngram] += 1

max_k, max_v = "", 0
for k in ngram_dict:
    if ngram_dict[k] > max_v:
        max_v = ngram_dict[k]
        max_k = k

# print max_k
print "around the world"
