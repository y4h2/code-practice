class Solution {
public:
    static bool cmp (const int &a , const int &b) {
        string s1 = to_string(a);    
        string s2 = to_string(b);
        string ab = s1 + s2;
        string ba = s2 + s1;
        return ab > ba;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string result = "";
        
        for (int i = 0; i < nums.size(); ++i)
            result += to_string(nums[i]);
        
        int i = 0;
        while(i < result.length() && result[i] == '0')
            ++i;
        
        if (i == result.length())
            return "0";
        
        return result.substr(i);
    }
};
