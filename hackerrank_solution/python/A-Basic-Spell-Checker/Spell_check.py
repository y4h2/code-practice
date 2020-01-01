
import sys
from collections import defaultdict
from nltk.metrics.distance import edit_distance
from scipy.spatial.distance import hamming


def ngrams(word):
    return set(zip(word, word[1:], word[2:]))


corpus = open("corpus.txt")
corpus_stats = defaultdict(lambda: 0)
for line in corpus:
    for word in line.strip().split():
        corpus_stats[word] += 1
        
filtered_corpus = {k: v for k,v in corpus_stats.iteritems() if v > 0}

ngram_index = defaultdict(set)
for cw in filtered_corpus.iterkeys():
    for bg in ngrams(cw):
        ngram_index[bg].add(cw)
        
sys.stdin.readline() # skip count
for line in sys.stdin:
    misspelled_word = line.strip()
    best_candidate = ""
    best_count = 0
    best_ed = 0
    ng_candidates = set()
    for ng in ngrams(misspelled_word):
        for cw in ngram_index[ng]:
            if abs(len(cw) - len(misspelled_word)) <= 1:
                ng_candidates.add(cw)
    
    
    if len(ng_candidates) > 50:
        ng_candidates_new = set()
        for cw in ng_candidates:
            if float(len(ngrams(cw) & ngrams(misspelled_word))) / len(ngrams(cw)) > 0.6:
                ng_candidates_new.add(cw)
        ng_candidates = ng_candidates_new
        
    #print bigrams(misspelled_word)
    #print misspelled_word, bg_candidates
    for cw in ng_candidates:
        count = filtered_corpus[cw]
        ed = edit_distance(cw, misspelled_word, transpositions=True)
        if (count > best_count and ed == 1) or (ed < best_ed):
            best_candidate = cw
            best_count = count
            best_ed = ed
            
    print best_candidate if best_candidate else misspelled_word
