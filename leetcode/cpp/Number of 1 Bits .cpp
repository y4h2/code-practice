class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int result = 0;
        uint32_t mask = 0x00000001;
        
        for (int i = 0; i < 32; ++i)
        {
            if ((n & mask) == 1)
                ++result;
            n >>= 1;
        }
        return result;
    }
};

/*
注意
不能用左移 mask <<= 1;
因为最后只能与1比较，左移则情况未知
*/
