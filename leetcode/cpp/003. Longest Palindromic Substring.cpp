/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string longestPalindrome(string s) 
    {
        if (s.size() <= 1) return s;
        
        int count1 = 0, count2 = 0;
        int maxLength = 1;
        string result = s.substr(0, 1);
        
        for (int i = 0; i < s.size() - 1; ++i)
        {
            //回文奇数的情况
            count1 = 0;
            while (i - count1 >= 0 && i + count1 < s.size())
            {
                if (s[i + count1] == s[i - count1])
                    ++count1;
                else
                    break;
            }
            --count1;
            if (1 + 2 * count1 > maxLength)
            {
                maxLength = 1 + 2 * count1;
                result = s.substr(i - count1, 2 * count1 + 1);
            }
            //回文为偶数的情况
            count2 = 0;
            while (i - count2 >= 0 && i + 1 + count2 < s.size())
            {
                if (s[i - count2] == s[i + 1 + count2])
                    ++count2;
                else
                    break;
            }
            //--count2;
            if (2 * count2 > maxLength)
            {
                maxLength = 2 * count2;
                result = s.substr(i + 1 - count2, 2 * count2);
            }
            
        }
        
        return result;
    }
};

// 暴力解法

class Solution {
public:
    string longestPalindrome(string s) {
        
        if (s.length() <= 1)
            return s;
            
        string result = "";
        
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 1; j + i <= s.length(); ++j) {
                string temp = s.substr(i, j);
                if ((temp.length() > result.length()) && testPalindrome(temp))
                    result = temp;
            }
        }
        
        return result;
    }
    
    bool testPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        
        while (i<j) {
            if (s[i] != s[j])
                return false;
            --j;
            ++i;
        }
        return true;
    }
};
```

## 从中间向两边扩展

1.substr方法过于耗时，尽量减少substr的次数
2. 注意初始化cnt1和cnt2的数值，让if条件只在成功判定后运行
3. 需要分奇数偶数讨论

```
class Solution {
public:
    string longestPalindrome(string s) {
        
        if (s.length() <= 1)
            return s;
            
        string result = "";
        
        for (int i = 0; i < s.length(); ++i) {
            
            //奇数
            int cnt1 = -1;
            for (int j = 1; j + i < s.length() && i - j >= 0; ++j ) {
                
                if (s[i-j] != s[i+j])
                    break;
                cnt1 = j;
            }
            
            if (cnt1 != -1 && 1 + cnt1 * 2 > result.length())
                result = s.substr(i - cnt1, 2*cnt1 + 1);
            
            //偶数
            int cnt2 = -1;
            for (int j = 0; j + i + 1 < s.length() && i - j >= 0; ++j ) {
                
                if (s[i-j] != s[i+1+j])
                    break;
                cnt2 = j;
            }
        
            if (cnt2 != -1 && 2*(cnt2 + 1) > result.length()) {
                cout << i - cnt2 << 2*(cnt2+1) << endl;
                result = s.substr(i - cnt2, 2*(cnt2+1));
            }
                
            
        }
        
        return result;
    }

};

// manache algorithm
class Solution {
public:
    string longestPalindrome(string S) {
        if (s.length() <= 1)
            return s;
            
        string result = "";
        
        // insert '#'
        string s = "#";
        for (int i = 0; i < S.length(); ++i) {
            s += S[i];
            s += "#";
        }
        int n = s.length();
        int center = 0, right = 0;
        vector<int> p(n);
        
        for (int i = 0; i < n; ++i) {
            int ii = (center << 1) - i;
            for (p[i] = (i < right) ? min(p[ii], right - i):0; (i-p[i]-1 >= 0)&&(i+p[i]+1 < n)&& (s[i-p[i] -1] == s[i+p[i]+1]); ++p[i]);
            if (i + p[i] > right) {
                right = i + p[i];
                center = i;
            }
        }
        
        int id = 0, max_len = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] > max_len) {
                id = i;
                max_len = p[i];
            }
        }
        string temp = s.substr(id - max_len, 2 * max_len + 1);
        
        for (int i = 0; i < temp.size(); ++i) {
            if (temp[i] != '#')
                result += temp[i];
        }
            
        return result;
    }
};
