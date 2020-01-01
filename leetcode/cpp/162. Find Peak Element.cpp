// O(n)解法
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] < nums[r])
                ++l;
            else
                --r;
        }
        
        return l;
    }
};

// 二分法
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] < nums[mid - 1] && nums[mid] > nums[mid + 1])
                r = mid;
            else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
                l = mid;
            else
                l = mid;
        }
        
        return nums[l] > nums[r] ? l : r;
    }
};

//  顺序查找
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
                return i - 1;
        }
        return nums.size() - 1;
    }
};
