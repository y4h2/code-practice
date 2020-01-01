/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
//迭代方法有些复杂，还没完全弄懂
//在学会dynamic programming之后，再做一遍




class Solution {
public:
    bool match(const char *s, const char *p)
    {
        if (*s == *p)
            return true;
        if (*p == '.' && *s != '\0')
            return true;
    
        return false;
    }
    
    bool isMatch(const char *s, const char *p) 
    {
        if (*p == '\0')
            return *s == '\0';
        
        if (*(p + 1) != '*')
        {
            if (match(s, p))
                return isMatch(s + 1, p + 1);
            else
                return false;
        }
        else
        {
            if (isMatch(s, p + 2)) return true; //尝试为空的情况
            while (match(s, p))  //尝试所有的长度
                if (isMatch(++s, p + 2)) // 注意++s通过，s+1效率最低，s++其次。主要原因是在循环中，++s改变了s指针的位置，每次循环的s都会往后移
                    return true;  //但是s+1的话每次循环都会回到最开始的s的值，相当于多了n^2的复杂度
        }
    }
};

//递归解法
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.length() == 0) return s.length() == 0;
        
        if (s[0] == p[0] || p[0] == '.' && s[0] != '\0')
            return (p.length() >= 1 && p[1] == '*') ? isMatch(s, p.substr(2)) || isMatch(s.substr(1), p) : isMatch(s.substr(1), p.substr(1));
        else
            return p[1] == '*' && isMatch(s, p.substr(2));
    }
};
