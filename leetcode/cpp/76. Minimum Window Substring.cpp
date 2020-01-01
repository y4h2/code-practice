class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";
        int head = 0, minHead = 0;
        int minLen = s.length() + 1;
        unordered_map<char, int> hashmap;
        int total = t.length();
        
        for (int i = 0; i < t.length(); ++i) {
            ++hashmap[t[i]];
        }
        
        for (int tail = 0; tail < s.length(); ++tail) {
            
            if (hashmap[s[tail]] > 0) {
                --total;
            }
            --hashmap[s[tail]];
              
            
            while(total == 0) {
                if (minLen > tail - head + 1) {
                    minLen = tail - head + 1;
                    minHead = head;
                }
                
                if (hashmap[s[head]] == 0)
                    ++total;
                ++hashmap[s[head]];
                ++head;
            }
        }
        
        if (minLen > s.length())
            return "";
        return s.substr(minHead, minLen);
    }
};
