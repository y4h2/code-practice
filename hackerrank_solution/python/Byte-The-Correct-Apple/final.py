# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
import re
sw_list  =  ['i', 'me', 'my', 'myself', 'we', 'our', 'ours', 'ourselves', 'you', 'your', 'yours',
'yourself', 'yourselves', 'he', 'him', 'his', 'himself', 'she', 'her', 'hers',
'herself', 'it', 'its', 'itself', 'they', 'them', 'their', 'theirs', 'themselves',
'what', 'which', 'who', 'whom', 'this', 'that', 'these', 'those', 'am', 'is', 'are',
'was', 'were', 'be', 'been', 'being', 'have', 'has', 'had', 'having', 'do', 'does',
'did', 'doing', 'a', 'an', 'the', 'and', 'but', 'if', 'or', 'because', 'as', 'until',
'while', 'of', 'at', 'by', 'for', 'with', 'about', 'against', 'between', 'into',
'through', 'during', 'before', 'after', 'above', 'below', 'to', 'from', 'up', 'down',
'in', 'out', 'on', 'off', 'over', 'under', 'again', 'further', 'then', 'once', 'here',
'there', 'when', 'where', 'why', 'how', 'all', 'any', 'both', 'each', 'few', 'more',
'most', 'other', 'some', 'such', 'no', 'nor', 'not', 'only', 'own', 'same', 'so',
'than', 'too', 'very', 's', 't', 'can', 'will', 'just', 'don', 'should', 'now']

def parse_text(text):
    #text = filter(lambda c: not c.isalnum() and c != ' ' or c!= '\n', text)
    return [w for w in text.split() if w not in sw_list]

def generate_bigrams(words):
    return set(zip(words, words[1:]))
    
cc_bigrams = generate_bigrams(parse_text(open("apple-computers.txt").read()))
fruit_bigrams = generate_bigrams(parse_text(open("apple-fruit.txt").read()))

cc_words = set(parse_text(open("apple-computers.txt").read()))
fruit_words = set(parse_text(open("apple-fruit.txt").read()))

def classify_is_cc(test_set, cc_set, fruit_set):
    score1 = len(cc_set & test_set)
    score2 = len(fruit_set & test_set)
    if score1 > score2:
        return 1
    return 0

def apple_sentence_stats(text):
    sentences = re.split(r' *[\.\?!][\'"\)\]]* *', text)
    capital_A_beginning = 0
    small_a = 0
    capital_A = 0
    for s in sentences:
        if s.startswith('Apple'):
            capital_A_beginning += 1
        words = s.split()
        for w in words:
            if w.startswith('Apple'):
                capital_A += 1
            if w.startswith('apple'):
                small_a += 1
    return small_a, capital_A, capital_A_beginning




sys.stdin.readline()
for line in sys.stdin:
    test_bigrams = generate_bigrams(parse_text(line.strip()))
    test_words = set(parse_text(line.strip()))
    method1 = classify_is_cc(test_bigrams, cc_bigrams, fruit_bigrams)
    method2 = classify_is_cc(test_words, cc_words, fruit_words)
    small_a, capital_A, capital_A_beginning = apple_sentence_stats(line.strip())
    method3 = (small_a == 0)
    if method1 + method2 + method3 > 1:
        print 'computer-company'
    else:
        print 'fruit'
