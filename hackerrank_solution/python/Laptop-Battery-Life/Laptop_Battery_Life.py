# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
data = float(sys.stdin.readline())

# Enter your code here
import numpy as np

training_data = np.genfromtxt('trainingdata.txt', delimiter=',')

#data preprocessing
features = training_data[:,0]
targets = training_data[:,1]
maximum_battery_life = targets.max()
minimum_charge_time = features[targets == maximum_battery_life].min()


targets = targets[features < minimum_charge_time]
features = features[features < minimum_charge_time]
features = features[targets < maximum_battery_life]
targets = targets[targets < maximum_battery_life]
targets = targets[features > 0]
features = features[features > 0]
features = features[targets > 0]
targets = targets[targets > 0]

features = np.transpose(np.atleast_2d(features))

#training model
from sklearn.linear_model import LinearRegression
lr = LinearRegression()
lr.fit(features, targets)
result = lr.predict(data)[0]

if data >= 4.00:
    print 8.00
else:
    print "{:0.2f}".format(round(result, 2))
