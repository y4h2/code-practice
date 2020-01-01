import re
def checkio(expression):
    pair = {']':'[', '}':'{', ')':'('}
    stack = []
    for character in expression:
        if re.match('[\(\{\[]', character):
            stack.append(character)
        if re.match('[\]\}\)]', character):
            if stack == []:
                return False
            else:
                if stack[-1] == pair[character]:
                    stack.pop()
                else:
                    return False
    return True if stack == [] else False
            
#better solution
def checkio(data):
    stack=[""]
    brackets={"(":")","[":"]","{":"}"}
    for c in data:
        if c in brackets:
            stack.append(brackets[c])
        elif c in brackets.values() and c!=stack.pop():
            return False
    return stack==[""]
