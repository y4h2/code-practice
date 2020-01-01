class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int m = num1.size(), n = num2.size();
        
        vector<int> v (m + n + 1, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                v[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        int sum = 0;
        for (int i = 0; i < v.size(); ++i) {
            sum += v[i];
            v[i] = sum % 10;
            sum /= 10;
        }
        
        reverse(v.begin(), v.end());
        
        bool zeroHead = true;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != 0)
                zeroHead = false;
            if (!zeroHead)
                result += v[i] + '0';
        }
        
        if (result == "") return "0";
        
        return result;
    }
};
