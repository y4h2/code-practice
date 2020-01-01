class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 0);
        vector<int> prev(n, 0);
        vector<int> result;
        int max = 0;
        int biggest_index = 0;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    
                    if (max < dp[i]) {
                        max = dp[i];
                        biggest_index = i;
                    }
                }
                
            }
        }
        
        for (int i = 0; i < max; ++i) {
            result.push_back(nums[biggest_index]);
            biggest_index = prev[biggest_index];
        }
        
        return result;
        
    }
};
