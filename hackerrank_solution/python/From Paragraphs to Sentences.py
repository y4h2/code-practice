# Enter your code here. Read input from STDIN. Print output to STDOUT
paragraph = raw_input()

punctuations = ".?!"
start, end = 0, 0
results = []
quote = False

for letter in paragraph:
    end += 1
    if letter == '"' and quote == False:
        quote = True
    elif letter == '"' and quote == True:
        quote = False
    elif letter in punctuations and quote == False:
        results.append(paragraph[start:end])
        start = end
    
        
#remove space
for line in results:
    if line.startswith(' '):
        line = line[1:]
    for _ in xrange(10000):
        print line
    
