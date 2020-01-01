/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
/*
算法思想;
首先从右往左找到第一个比右边小的数字，称为val
再从最右边开始找比val小的数字，因为上述条件，所以在val右边的数字都是从右往左依次递增的
第一个比val大的数字，就是最接近val的数
把这两个数字交换之后，把val右边的所有数字按逆序排成最小的数字即可
*/



class Solution {
public:
    void nextPermutation(vector<int> &num) 
    {
        if (0 == num.size() || 1 == num.size()) return ;
        int n = num.size();
        int index = n - 1; //需要交换的位置
        int j = n - 1;
        while (index > 0)
        {
            if (num[index] > num[index - 1]) //index - 1是需要交换的位置
                break;
            --index;
        }
        if (0 == index)
        {
            reverseSort(num, 0, n - 1);
            return;
        }
        else if (n - 1 == index)
        {
            swap(num, n - 1, n - 2);
            return;
        }
        else    
        {    
            while (j >= index)
            {
                if (num[j] > num[index - 1])
                    break;
                --j;
            }
            swap(num, index - 1, j);
            reverseSort(num, index, n - 1);
            return;
        }
        
        
    }
    
    void reverseSort (vector<int> &num, int begin, int end)
    {
        if (begin > end) return;
        for (int i = begin; i <= (end + begin) / 2; ++i)
        {
            swap(num, i, begin + end - i);
        }
    }
    
    void swap (vector<int> &num, int i, int j)
    {
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
};
