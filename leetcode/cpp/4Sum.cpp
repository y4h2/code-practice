/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
//如果仿照sum3的方法，则会超时
//这里使用hash表，存入2个数的和的hash值，后面对应查找即可

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) 
    {
        vector<vector<int> > result;
        if (num.size() <= 3) return result;
        sort (num.begin(), num.end());
        
        unordered_map<int, vector<pair<int, int> > > mp;
        
        for (int i = 0; i < num.size(); ++i)
        {
            for (int j = i + 1; j < num.size(); ++j)
            {
                mp[num[i] + num[j]].push_back(make_pair(i, j));
            }
        }
        
        for (int i = 0; i < num.size(); ++i)
        {
            if (i > 0 && num[i] == num[i - 1]) continue;
            for (int j = i + 1; j < num.size(); ++j)
            {
                if (j > i + 1 && num[j] == num[j - 1]) continue;
                int temp = target - num[i] - num[j];
                if (mp.count(temp) > 0)
                {
                    for (auto it = mp[temp].begin(); it < mp[temp].end(); ++it)
                    {
                        int k = it->first, l = it->second;
                        if (k > j) //确保k，l和i，j不同
                        {
                            if (!result.empty() && result.back()[0] == num[i] && result.back()[1] == num[j] && 
                            result.back()[2] == num[k] && result.back()[3] == num[l]) //确保答案中不重复
                                continue;
                            vector<int> buffer = {num[i], num[j], num[k], num[l]};
                            result.push_back(buffer);
                        }
                    }
                }
            }
        }
        
        return result;
    }
};


//N sum 常规解法
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) 
    {
        vector<vector<int> > result;
        if (num.size() <= 3) return result;
        sort (num.begin(), num.end());
        
        
        for (int i = 0; i < num.size() - 3; ++i)
        {
            if (i > 0 && num[i] == num[i - 1]) 
                continue;
            for (int j = i + 1; j < num.size() - 2; ++j)
            {
                if (j > i + 1 && num[j] == num[j - 1]) 
                    continue;
                int p = j + 1, q = num.size() - 1;
                while (p < q)
                {
                    int ans = num[i] + num[j] + num[p] + num[q];
                    if (ans == target)
                    {
                        result.push_back({num[i], num[j], num[p], num[q]});
                        ++p;
                        while(p < num.size() && num[p - 1] == num[p])
                            ++p;
                        --q;
                        while(q >= 0 && num[q + 1] == num[q])
                            --q;
                    }
                    else if (ans < target)
                        ++p;
                    else
                        --q;
                }
                
            }
        }
        
        return result;
    }
};
