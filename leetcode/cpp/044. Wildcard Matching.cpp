//完全递归
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) return s.length() == 0;
        if (s.length() == 0) {
            for (int i = 0; i < p.length(); ++i) {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }
        
        if (s[0] == p[0] || p[0] == '?') {
            return isMatch(s.substr(1), p.substr(1));
        }
        else if (p[0] == '*') {
            return isMatch(s.substr(1), p) || isMatch(s, p.substr(1));
        }
        else
            return false;
    }
};

//部分递归
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) return s.length() == 0;
        if (s.length() == 0) {
            for (int i = 0; i < p.length(); ++i) {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }
        
        int i;
        for (i = 0; i < s.length() && i < p.length(); ++i) {
            
            if (s[i] == p[i] || p[i] == '?')
                continue;
            else if (p[i] == '*') 
                return isMatch(s.substr(1+i),p.substr(i)) || isMatch(s.substr(i), p.substr(1+i));
            else
                return false;
        }
        
        return isMatch(s.substr(i), p.substr(i));
    }
};

//DP
