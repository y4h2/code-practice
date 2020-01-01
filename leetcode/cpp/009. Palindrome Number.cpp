class Solution {
public:
    bool isPalindrome(int x) 
    {
        if (x < 0) return false;
        
        int left  = pow(10, floor(log10(x)));
        int right = 1;
        
        while(right < left)
        {
            if ((x / left - x / right) % 10 != 0)
                return false;
            left /= 10;
            right *= 10;
        }
        
        return true;
    }
};

//reverse int的方法
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if (x == 0)
            return true;
        else if (x < 0)
            return false;
        else 
            return x == reverse(x);
    }
    
    int reverse (int x)
    {
        int rev = 0;
        while ( x != 0)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
        
    }
};


class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) return false;
        else if (x < 10) return true;

        int temp = x;
        int reverse_x = 0;
        
        while (temp != 0) {
            if (reverse_x > INT_MAX / 10 || (reverse_x == INT_MAX / 10 && temp % 10 > INT_MAX % 10))
                return false;
            reverse_x = reverse_x * 10 + temp % 10;
            temp /= 10;
        }
        
        return x == reverse_x;
    }
};

//翻转一半
class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || (x != 0 && x%10 == 0)) return false;
       

        int reverse_x = 0;
        
        while (x > reverse_x) {
            reverse_x = reverse_x * 10 + x % 10;
            x /= 10;
        }
        
        return (x == reverse_x) || (x == reverse_x / 10);
    }
};
