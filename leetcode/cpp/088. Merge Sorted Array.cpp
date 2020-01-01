
//从后往前遍历
class Solution {
public:
    void merge(int A[], int m, int B[], int n) 
    {
        int p = m - 1, q = n - 1;
        int i = m + n - 1;
        while ((p >= 0) && (q >= 0))  //only operate when both A and B have elements
        {
            if (A[p] < B[q])   // merge two arrays in A, put these elements in the tail of A, can save space
            {
                A[i--] = B[q--];
            }
            else
            {
                A[i--] = A[p--];
            }
        }
        
        while (q >= 0)  //只有B还剩元素时,才进行操作,如果只剩A有元素则不用操作
            A[i--] = B[q--];
        
    }
};

// 从前往后遍历
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            for (int i = 0; i < n; ++i)
                nums1[i] = nums2[i];
            return;
        }
        
        int i = 0, j = 0, left_elem = m;
        
        while (j < n && i < nums1.size()) {
            if (left_elem == 0) {
                nums1[i] = nums2[j];
                ++i;
                ++j;
            }
            else {
                 if (nums1[i] <= nums2[j]) {
                    ++i;
                    --left_elem;
                }
                    
                else{
                    for (int k = m - 1; k >= i; --k) {
                        nums1[k + 1] = nums1[k];
                    }
                    nums1[i] = nums2[j];
                    
                    ++i;
                    ++j;
                    ++m;
                }
            }
           
        }
        
        return;
    }
};
