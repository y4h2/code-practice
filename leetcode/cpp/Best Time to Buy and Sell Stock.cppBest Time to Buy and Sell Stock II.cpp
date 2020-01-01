/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
//贪心算法，只考虑最近能获得的最大利益
//该算法不能保证一定鞥呢获利，但是能保证在获利情况下得到最大值


class Solution {
public:
    int maxProfit(vector<int> &prices) 
    {
        int result = 0;
        for (int i = 0; i + 1 < prices.size(); ++i)
        {
            if (prices[i] < prices[i + 1])
                result += prices[i + 1] - prices[i];
        }
        
        return result;
    }
};
