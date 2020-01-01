class Solution {
public:
    string convert(string s, int nRows) 
    {
        string result;
        if (( nRows == 1 ) || (s.length() < nRows) || (s.length() == 1)) return s;
        //首先排除不需要变换的特殊情况
        int distance = 2 * (nRows - 1); 
        int offset = 0;
        
//0       6       12    -> distance = 2(nRows-1) = 6 offset = 0
//1    5  7     11        -> offset =  distance - 2 = 4
//2  4    8  10            -> offset = distance -2 -2 = 2
//3       9                  -> distance = 2(nRows-1) = 6 offset = 0
//由上图观察可知，如果只考虑元素个数为nRows的那几列，那么间隔distance固定。
//每两个满元素列之间，除去第一个层和最后一层，只相隔一个元素。这个元素用相对于左边元素的偏移量offset表示即可
//启发，同理对于其他类似题目，可以采用同样方法，根据序号出现的次序画图，判断规律。
        
        for (int row = 0; row < nRows; ++row)
        {
            for (int index = row; index < s.length(); index += distance)
            {
                result += s[index];
                if ((offset != 0) && (index + distance - offset < s.length()))
                {
                    result += s[index + distance - offset];
                }
            }
            offset += 2;
            offset %= distance;
        }
    
        return result;    
    }
};

//更为直观，且时间复杂度为O(N)
class Solution {
public:
    string convert(string s, int numRows) 
    {
        if (numRows <= 1)
            return s;
            
        string result = "";
        vector<string> tmp(numRows, "");
        int step = 1;
        int row = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            tmp[row] += s[i];
            
            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;
                
            row += step;
        }
        
        for (int i = 0; i < numRows; ++i)
            result += tmp[i];
        
        return result;
    }
};
