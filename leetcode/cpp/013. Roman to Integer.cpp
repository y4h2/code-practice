class Solution {
public:
    int romanToInt(string s) 
    {
        int result = 0;
        
        map <char, int> stand = {    //用map结构可以高效的替代case语句
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        for (int i = 0; i < s.size(); ++i)
        {
            if( (i + 1 < s.size()) && (stand[s[i]] < stand[s[i + 1]]))  //罗马数字规则，当在较大的罗马数字的左边记上较小的罗马数字，表示大数字减小数字
            {
                result += stand[s[i + 1]] - stand[s[i]];
                ++i;
            }
            else
            {
                result += stand[s[i]]; //在较大的罗马数字的右边记上较小的罗马数字，表示大数字加小数字
            }
        }
        
        
        return result;
    }
};

//优化版
class Solution {

private:
    map <char, int> stand = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
    
public:
    int romanToInt(string s) {
        int result = 0;
        for ( int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && stand[s[i]] < stand[s[i+1]])
                result -= stand[s[i]];
            else
                result += stand[s[i]];
        }
        
        return result;
    }
};
