/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

//anagrams是变位词，在map中保存其字典序作为hash值，还有当前的序号

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) 
    {
        vector<string> result;
        if (strs.size() < 2) return result; 
        unordered_map <string, int> cache;
        
        for (int i = 0; i < strs.size(); ++i)
        {
            string buffer = strs[i];
            sort(buffer.begin(), buffer.end());
            auto it = cache.find(buffer); //寻找是否存在变位词
            if (it == cache.end()) //一组变位词，只把第一个遇到的记录进hash表
                cache[buffer] = i;
            else
            { 
                
                if (it->second != -1) //这里确保只会把第一个被记录进来的放入result一次
                {
                    result.push_back(strs[it->second]);
                    it->second = -1; //如果已经存入result中，则标记为-1
                }
                result.push_back(strs[i]); //先检查，再插入新值，可确保相对位置不变
            }
        }
        
        return result;
    }
};
