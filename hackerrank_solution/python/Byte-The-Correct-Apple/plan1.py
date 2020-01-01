# Enter your code here. Read input from STDIN. Print output to STDOUT
cc_words = set(open("apple-computers.txt").read().split())
fruit_words = set(open("apple-fruit.txt").read().split())

# simply classify as which has most common words
def classify(set_of_words):
    if len(set_of_words & cc_words) > len(set_of_words & fruit_words):
        return "computer-company"
    else:
        return "fruit"
 
import sys
sys.stdin.readline()
for line in sys.stdin:
    set_of_words = set(line.strip().split())
    print classify(set_of_words)
