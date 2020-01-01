// hash table

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        vector<int> result;
        if (nums1.empty() || nums2.empty())
            return result;
        
        for (int i = 0; i < nums1.size(); ++i) {
            ++hashmap[nums1[i]];
        }
        
        for (int i = 0; i < nums2.size(); ++i) {
            if (hashmap[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                --hashmap[nums2[i]];
            }
        }
        
        return result;
    }
};
