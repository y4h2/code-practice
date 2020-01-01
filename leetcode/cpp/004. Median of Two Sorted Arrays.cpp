class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m+n)%2 == 0)
            return (getMedian(nums1.begin(), m, nums2.begin(), n, (m+n)/2) + getMedian(nums1.begin(), m, nums2.begin(), n, (m+n)/2 + 1))/2;
        else
            return getMedian(nums1.begin(), m, nums2.begin(), n, (m+n)/2 + 1); 
    }
    
    double getMedian(vector<int>::iterator iter1, int m, vector<int>::iterator iter2, int n, int k){
        if (m <= 0) return (double) *(iter2 + k - 1);
        if (n <= 0) return (double) *(iter1 + k - 1);
        if (k <= 1) return (double) min(*iter1, *iter2);
        if ((m/2 + n/2 + 1) >= k) {
            if (*(iter1 + m/2) >= *(iter2 + n/2))
                return getMedian(iter1, m/2, iter2, n, k);
            else
                return getMedian(iter1, m, iter2, n/2, k);
        }
        else {
            if (*(iter1 + m/2) >= *(iter2 + n/2))
                return getMedian(iter1, m, iter2 + n/2 + 1, n - (n/2 + 1), k - (n/2 + 1));
            else
                return getMedian(iter1 + m/2 + 1, m - (m/2 + 1), iter2, n, k - (m/2 + 1));
        }
    }
};


//归并
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m+n) & 1)
            return getMedian(nums1.begin(), m, nums2.begin(), n, (m + n + 1)>>1);
        else
            return (getMedian(nums1.begin(), m, nums2.begin(), n, (m + n) >> 1) + getMedian(nums1.begin(), m, nums2.begin(), n, ((m + n) >> 1 ) + 1)) * .5;
    }
    
    int getMedian(vector<int>::iterator iter1, int m, vector<int>::iterator iter2, int n, int k){
        int i = 0, j = 0;
        
        for ( ; i < m && j < n;) {
            --k;
            if (*(iter1 + i) < *(iter2 + j)) {
                if (k == 0)
                    return *(iter1 + i);
                ++i;
            }
            else {
                if (k == 0) {
                    return *(iter2 + j);   
                }
                ++j;
            }
        }
        
        return (i >= m) ? *(iter2 + j + k - 1) : *(iter1 + i + k - 1);
    }
};

//分治
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m+n) & 1)
            return getMedian(nums1.begin(), m, nums2.begin(), n, (m + n + 1)>>1);
        else
            return (getMedian(nums1.begin(), m, nums2.begin(), n, (m + n) >> 1) + getMedian(nums1.begin(), m, nums2.begin(), n, ((m + n) >> 1 ) + 1)) * .5;
    }
    
    int getMedian(vector<int>::iterator iter1, int m, vector<int>::iterator iter2, int n, int k){
        // 确保m < n
        if (m > n)
            return getMedian(iter2, n, iter1, m, k);
        if (m == 0)
            return *(iter2 + k - 1);
        
        if (k == 1)
            return min(*iter1, *iter2);
        
        int pa = min(k >> 1, m), pb = k - pa;
        return( *(iter1 + pa - 1) < *(iter2 + pb - 1)) ? getMedian(iter1 + pa, m - pa, iter2, pb, k - pa) : getMedian(iter1, pa, iter2 + pb, n - pb, k - pb);
    }
};
