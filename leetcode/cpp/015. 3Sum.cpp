/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
//注意：3个数字相加的算法，后面的两个变量，一定要放在循环内部初始化，因为每次循环，都需要重新赋值
//该题多了一个确保小于最多只有两个数重复的条件，所以要使用while循环移除
//i和j可以保证取到前两个相同的情况，k可以保证取到后两个相同的情况
//之所以把j和k的循环放在相等的情况中，是为了让初始化的时候，判断num[i]和num[j]相等的情况下是否存在解
//如果存在，i不变，后面再寻找num[j]和num[k]相等的情况是否存在
//并且要注意，最后类似寻找多解的题目，一定要在相等情况下改变指针位置，不然会陷入死循环


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int> > result;
        if (num.size() < 3) return result;
        
        int ans = 0;

        sort(num.begin(), num.end());
        
        for (int i = 0;i < num.size() - 2; ++i)
        {
            if (i > 0 && num[i] == num[i - 1])  
                continue;
            int j = i + 1;
            int k = num.size() - 1;

            while (j < k)
            {
                ans = num[i] + num[j] + num[k];

                if (ans == 0)
                {
                    result.push_back({num[i], num[j], num[k]});
                    ++j;
                    while (j < num.size() && num[j] == num[j - 1])//only use the first j if there is a series of same num
                        ++j;
                    --k;
                    while (k >= 0 && num[k] == num[k + 1])//only use the last k if there is a series of same num
                        --k;
                }
                else if (ans > 0) --k;
                else ++j;
                
            }
        }
        
        
        return result;
    }
};
