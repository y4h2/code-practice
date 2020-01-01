/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

//注意卖出的时间在买入的之后即可

class Solution {
public:
    int maxProfit(vector<int> &prices) 
    {
        int min = 0;
        int diff = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < prices[min])
                min = i;
            if (diff < prices[i] - prices[min])
                diff = prices[i] - prices[min];
        }
        
        return diff;
        
    }
};
