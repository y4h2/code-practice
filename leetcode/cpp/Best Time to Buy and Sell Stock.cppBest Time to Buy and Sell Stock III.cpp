/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) 
    {
        if (prices.size() <= 1) return 0;
        
        int times = 2;
        int maxProfit = 0;
        vector<vector<int> > dp (times + 1, vector<int>(prices.size(), 0));
        // f[k, ii] represents the max profit up until prices[ii] 
        
        for (int i = 1; i <= times; ++i)
        {
            int tempProfit = dp[i - 1][0] - prices[0]; //第二次购是在第一次的基础上的
            for (int j = 1; j < prices.size(); ++j)
            {
                dp[i][j] = max (dp[i][j - 1], prices[j] + tempProfit);
                tempProfit = max(tempProfit, dp[i - 1][j] - prices[j]);
                maxProfit = max (maxProfit, dp[i][j]);
            }
        }
        
        return maxProfit;
        
    }
};
