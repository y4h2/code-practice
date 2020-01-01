//先移位，后加
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        int flag = 1;
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i)
        {
            result <<= 1;
            result |= flag & n;
            n >>= 1;
        }
        return result;
    }
};
