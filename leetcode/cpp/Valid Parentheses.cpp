/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
//这题简单在于没有其他符号的干扰，只要栈顶元素不是对应元素，即为错


class Solution {
public:
    bool isValid(string s) 
    {
        if (s.length() == 0) return true;
        if (s.length() == 1) return false;
        
        stack<char> buffer;
        for (int i = 0; i < s.length(); ++i)        
        {
            if (buffer.empty() || s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                buffer.push(s[i]);
            }
            else
            {
                switch(s[i])
                {
                    case '}' :
                        if (buffer.top() == '{') buffer.pop();
                        else return false;
                        break;
                    case ']' :
                        if (buffer.top() == '[') buffer.pop();
                        else return false;
                        break;
                    case ')' :
                        if (buffer.top() == '(') buffer.pop();
                        else return false;
                        break;
                    default :
                        return false;
                }
            }

        }
        if (!buffer.empty())
            return false;
        
        return true;
    }
};
