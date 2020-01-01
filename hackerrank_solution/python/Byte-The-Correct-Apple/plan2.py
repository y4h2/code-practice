import sys
from collections import defaultdict
#from nltk.corpus import stopwords

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

def calc_stats(text):
    res = defaultdict(lambda: 0)
    words = text.split()
    for w in words:
        if w not in sw_list:
            res[w] += 1
    return res
        
# Enter your code here. Read input from STDIN. Print output to STDOUT
cc_stats = calc_stats(open("apple-computers.txt").read())
fruit_stats = calc_stats(open("apple-fruit.txt").read())

def classify(list_of_words):
    def score(stats, low):
        res = 0
        for w in low:
            res += stats[w]
            
        return res
    
    if score(cc_stats, list_of_words) > score(fruit_stats, list_of_words):
        return "computer-company"
    else:
        return "fruit"

sys.stdin.readline()
for line in sys.stdin:
    list_of_words = line.strip().split()
    print classify(list_of_words)
