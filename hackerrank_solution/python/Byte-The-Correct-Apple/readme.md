[Problem link](https://www.hackerrank.com/challenges/byte-the-correct-apple) <br/>
Following Alexander Putilin's youtube records, [Solving AI HackerRank Challenges](https://www.youtube.com/watch?v=dPvWZhjL_Nk)<br/>

it's a classification problem

#training data
two wikipedia pages of Apple company and fruit apple
"apple-computers.txt"
"apple-fruit.txt"

# Plan
1) divide wikipedia articles into individual words
2) save these lists somewhere

Classification:<br/>
1) calculate intersection of words in wiki articles and test it <br/>
This is [plan one](./plan1.py) [score: 74] <br/>
2) add stop words <br/>
[Plan 2](./plan2.py) [score: 58] <br/>
3) add stop words directly in plan1
[plan 3](./plan3.py)
4) remove common words of two documents
```python
common_words = cc_words & fruit_words

fruit_words -= common_words
cc_words -= common_words
```
5) test whether the number of captial A influence the result

6) use bigrams

7) combine three methods <br/>
chose the majority selection as result
[Final result](./final.py)
