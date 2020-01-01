class Solution {
public:

    vector<string> split(string s) {
        vector<string> result;
        
        int i = 0, j = 0;
        while(i < s.length() && j <= s.length()) {
            if (s[j] == ' ' || s[j] == '\0') {
                result.push_back(s.substr(i, j - i));
                i = j + 1;
                ++j;
            }
            else
                ++j;
        }
        
        return result;
    }
    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str);
        unordered_map<string, int> word_map;
        unordered_map<char, char> pattern_map;
        
        if(words.size() != pattern.length())
            return false;
        
        for(int i = 0; i < words.size(); ++i) {
            if (word_map.find(words[i]) == word_map.end() && ) {
                word_map[words[i]] = i;
            }
            else if (word_map[words[i]] != pattern[i]) {
                return false;
            }
            if (pattern_map.find(pattern[i]) == pattern_map.end()) {
                pattern_map[pattern[i]] = words[i];
            }
            else if (pattern_map[pattern[i]] != words[i]) {
                return false;
            }
        }
        
        return true;
    }
};
