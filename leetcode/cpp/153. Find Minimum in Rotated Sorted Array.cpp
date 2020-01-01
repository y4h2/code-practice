/* solution 1 O(n) */
class Solution {
public:
    int findMin(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i - 1] > nums[i])
                return nums[i];
        }
        
        return nums[0];
    }
};

/*solution 2 log(n)*/
class Solution {
    public:
        int findMin(vector<int> &num) {
            int n = num.size();
            int low = 0, high = n-1;
            while(num[low] > num[high]) {    //二分法，在左边小于右边的情况下操作，唯一的一个右边小于左边的元素即为所求
                int mid = (low+high) >> 1;   //移位操作的效率比乘除法要高
                if(num[low] <= num[mid])
                    low = mid+1;
                else if(num[mid] < num[high])
                    high = mid;
            }
            return num[low];
        }
    };
