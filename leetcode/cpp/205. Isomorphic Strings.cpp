class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) 
            return false;
        unordered_map<char, int> m1, m2;
        
        for (int i = 0; i < s.length(); ++i) {
            if (m1.find(s[i]) != m1.end() || m2.find(t[i]) != m2.end()) {
                if ( m1[s[i]] != m2[t[i]])
                    return false;
            }
            else {
                m1[s[i]] = i + 1;
                m2[t[i]] = i + 1;
            }
        }
        
        return true;
    }
};
