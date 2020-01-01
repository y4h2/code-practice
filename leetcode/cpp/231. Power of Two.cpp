class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while(n > 0) {
            if (n & 1)
                ++cnt;
            n >>= 1;
        }
        
        return cnt == 1;
    }
};


class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && 2147483648 % n == 0;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1) == 0);
    }
};
