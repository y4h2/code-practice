/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

//特别注意，字符串的序号是从左向右， 但是计数是从右向左


class Solution {
public:
    string addBinary(string a, string b) 
    {
        string result, t;
        int i = 0;
        int temp = 0;
        
        if (a.length() == 0 && b.length() == 0)
            return result;
        if (a.length() == 0 || b.length() == 0)
            return a.length() == 0 ? b : a;
        
        if (a.length() < b.length())
        {
            for (int j = a.length(); j < b.length(); ++j)
            {
                t += "0";
            }
            a = t + a;
        }
        else if (b.length() < a.length())
        {
            for (int j = b.length(); j < a.length(); ++j)
            {
                t += "0";
            }
            b = t + b;
        }
        result = a;
        i = a.length() - 1;
        while (i >= 0)
        {
            result[i] = '0' + ((a[i] - '0') + (b[i] - '0') + temp) % 2;
            temp = ((a[i] - '0') + (b[i] - '0') + temp) / 2;
            --i;
        }
        if (temp == 1)
        {
            return "1" + result;
        }
        
        return result;
    }
};
