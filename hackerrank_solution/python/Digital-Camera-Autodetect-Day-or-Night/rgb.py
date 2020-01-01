import sys

sumV = 0
numPixels = 0

for line in sys.stdin:
    rgb_tuples = line.strip().split(' ')
    for t in rgb_tuples:
        r, g, b = map(int, t.split(','))
        cmax = max(r,g,b)
        sumV += cmax
        numPixels += 1
    
if float(sumV) / numPixels > 100:
    print "day"
else:
    print "night"
