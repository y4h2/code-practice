class Solution:
    # @return a boolean
    def isValid(self, s):
        brackets = {'(': ')', '[': ']', '{': '}'}
        stack = []
        for i in s:
            if i in brackets:
                stack.append(brackets[i])
            elif i in brackets.values():
                if stack == []:
                    return False
                elif i == stack[-1]:
                    stack.pop()
                else:
                    return False
        return stack == []
                
