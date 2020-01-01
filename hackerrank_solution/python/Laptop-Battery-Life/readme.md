#Problem Description
You will be able to access Fred’s laptop charging log by reading from the file “trainingdata.txt”. The training data file will consist of 100 lines, each with 2 comma-separated numbers. The first number denotes the amount of time the laptop was charged and the second denotes the amount of time the battery lasted. The training data file can be downloaded here (this will be the same training data used when your program is run). The input for each of the test cases will consist of exactly 1 number rounded to 2 decimal places. For each input, output 1 number: the amount of time you predict his battery will last.

# Problem Analyze
This is a Regression problem, and only one column input and one column output. The simplest solution is using Linear Regression.
The storage of battery is limited. 如果充满电，多余的时间不会再增加续航时间。
We have to find the maximum of battery life(8.00) and minimum time(4.00) to fill the battery. 

Doing data cleaning, only use features in [0, 4.11], targets in [0, 8.00]

```python
targets.max() #8.00
features[targets == targets.max()].min() # 4.11
```

In terms of output, should consider that if charge more than 4.11, the battery life will never beyond 8.oo
