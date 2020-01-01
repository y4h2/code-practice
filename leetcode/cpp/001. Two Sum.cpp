//几个特殊用例
// {0, 3, 2, 0} 0
// {3, 2, 4} 6

//88ms
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
        vector<int> v, results;
        int index1 = 0, index2 = 0, num = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            v.push_back (numbers[i]); //不能直接在numbers上面操作，因为序号是根据numbers里面的序号来的
        }
        sort (v.begin(), v.end());
        
        for (int i = 0; i < v.size(); i++)
        {
            if(binary_search (v.begin(), v.end(), target - v[i])) //由二分查找快速确认元素是否存在
            { 
                num = v[i];
                break;
            }
        }
        
        int count = 0;
        for (int j = 0; j < numbers.size(); j++) //在原序列中定位元素位置
        {
     
                if (numbers[j] == target - num && count ==0)  //由于可能出现两个0的情况，为了防止两个标记的序号相同
                {                                       //所以用count标记个数，同样可以推广到3个数的情况
                    index1 = j + 1;                 //特殊情况，如{0，3，0} 0，期望结果为1,3. 如果没有count，则会是3,3
                    count++;
                }
                if (numbers[j] == num)
                    index2 = j + 1;
  

        }
        
        if (index1 < index2)   //保证结果中index1小于index2
        {
            results.push_back(index1);
            results.push_back(index2);
        }
        else
        {
            results.push_back(index2);
            results.push_back(index1);
        }
        return results;
    }
};

//第二遍刷题 68ms
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
        vector<int> result;
        if (numbers.size() == 0) return result;
        
        vector<int> hashTable;
        for (int i = 0; i < numbers.size(); ++i)
            hashTable.push_back(numbers[i]);
        
        sort (hashTable.begin(), hashTable.end());
        int i = 0, j = hashTable.size() - 1;
        
        while (i < j)
        {
            if (hashTable[i] == target - hashTable[j])
                break;
            else if (hashTable[i] < target - hashTable[j])
                ++i;
            else
                --j;
        }
        
        for (int index = 0; index < numbers.size(); ++index)
        {
            if (numbers[index] == hashTable[i] || numbers[index] == hashTable[j])
                result.push_back(index + 1);
        }
        
        if (result[0] > result[1])
            swap(result[0], result[1]);
        
        return result;
    }
};

//使用hash表 48ms 
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
        vector<int> result;
        unordered_map<int, int> hash;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (hash.find(target - numbers[i]) != hash.end())
            {  //保证了 大小顺序，因为这时numbers[i]还不在hash表中，出现在前面的元素会先进入hash表
                result.push_back(hash[target - numbers[i]] + 1);
                result.push_back(i + 1);
                break;
            }
            hash[numbers[i]] = i; //元素重复也不会产生冲突
        }
        
        return result;
    }
};


// 非hash表解法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results;
        int n = nums.size();
        if (n < 2)
            return results;
        
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());
        
        int temp;
        
        for (int i = 0; i < n; ++i) {
            temp = sorted_nums[i];
            if (binary_search(sorted_nums.begin(), sorted_nums.end(), target - temp))
                break;
        }
        
        for (int i = 0; i < n; ++i)
            if (nums[i] == temp || nums[i] == target - temp)
                results.push_back(i);
        
        return results;
    }
};
