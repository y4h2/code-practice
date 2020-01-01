// 由于空格数目不定，所以最后再组装字符串

// 字符串分为最后一个字符串和其他字符串
class Solution {
public:
    string generateLastSentence(vector<string> v, int cnt, int maxWidth) {
        string s;
        for(int k = 0; k < v.size(); ++k) {
            s += v[k];
            if (s.length() < maxWidth) {
                s += " ";
            }
        }
        string t (maxWidth - s.length(), ' ');
        s += t;
        
        return s;
    }

    string generateSentence(vector<string> v, int cnt, int maxWidth) {
        string s;
        
        if (v.size() == 1) {
            string temp (maxWidth - cnt, ' ');
            s += v[0] + temp;
        }
        if (v.size() > 1) {
            int numSpace = (maxWidth - cnt) / (v.size() - 1);
            int extraSpace = (maxWidth - cnt) % (v.size() - 1);
            for (int i = 0; i < v.size(); ++i) {
                if (i == v.size() - 1) {
                    s += v[i];
                }
                else {
                    string temp(numSpace, ' ');
                    s += v[i] + temp + (extraSpace > i ? " " : "");
                }
            }
        }
        
        return s;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int cnt = 0; // len of words in sentence, without space
        vector<string> temp;
        int i = 0;
        while (i < words.size()) {
            if (words[i].length() > maxWidth)
                return vector<string> (0);
            
            if (cnt + temp.size() + words[i].length() <= maxWidth) {
                temp.push_back(words[i]);
                cnt += words[i].length();
                ++i;
            }
            
            if (i == words.size() || cnt + temp.size() + words[i].length() > maxWidth) {
                string s = "";
                if (i == words.size()) {
                    s = generateLastSentence(temp, cnt, maxWidth);
                }
                else {
                    s = generateSentence(temp, cnt, maxWidth);
                }
                
                result.push_back(s);
                temp.clear();
                cnt = 0;
            }
            
        }
        
        return result;
    }
};
