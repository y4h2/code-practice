/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
//注意领会题目意思，第n个数是根据第n+1个数求来的。


class Solution {
public:
    string countAndSay(int n) 
    {
        string curString;
        string preString;
        char temp;
        int cnt = 1;
        
        if (n == 0) return "";
        if (n == 1) return "1";
        
        curString = "1"; //注意单引号和双引号的使用，单引号用于char，双引号用于字符串，如果错用，会出现warn:multi-character character constant
        
        for (int i = 1; i < n ;++i)
        {
            preString = curString;
            curString = "";
            temp = preString[0];
            
            for (int j = 1; j < preString.length(); ++j)
            {
                if (temp == preString[j])
                {
                    ++cnt;
                }
                else
                {
                    curString += (cnt + '0'); //itoa
                    curString += temp;
                    temp = preString[j];
                    cnt = 1;
                }
                
            }
            
            curString += cnt + '0'; //结尾的地方一定要在循环外部加上，不可能在循环内部完成
            curString += temp;
            cnt = 1; //记得循环外也要归位，或者创建为循环内临时变量，每次循环重新赋值
            
        }
         
        return curString;
    }
    
    
class Solution {
public:

    string generateNext(string s) {
        string result = "";
        int cnt = 1;
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && s[i] == s[i - 1])
                ++cnt;
            if (i > 0 && s[i] != s[i - 1]) {
                result += to_string(cnt) + s[i - 1];
                cnt = 1;
            }
        }
        
        result += to_string(cnt) + s[s.length() - 1];
        
        return result;
    }
    string countAndSay(int n) {
        string result = "1";
        if (n == 1) return result;
        
        
        while(--n > 0) {
            result = generateNext(result);
        }
        
        
        return result;
    }
};
    
};
