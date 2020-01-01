class Solution {
public:
    void help(vector<vector<int>> &result, vector<int> nums, vector<int> temp, int index) {
        result.push_back(temp);

           
        for (int i = index; i < nums.size(); ++i) {
            if (i != index && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            help(result, nums, temp, i + 1);
            temp.pop_back();
        }
        
        return;
            
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        
        if (nums.size() == 0)
            return result;
        
        sort(nums.begin(), nums.end());
        vector<int> temp;
        help(result, nums, temp, 0);
        
        return result;
    }
};
