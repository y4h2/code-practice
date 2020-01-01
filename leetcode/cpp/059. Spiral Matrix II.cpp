/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

//需要一个方向参数，得知当前的移动方向
//再通过预先的标记，判断是否转换方向即可

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) 
    {
        vector<vector<int> > result(n, vector<int>(n, -1));
        int num = 1;
        int i = 0, j = 0; //注意i和j的范围在0到n-1之间，判断越界的时候注意边界
        int dir = 1;
        
        while (num <= n * n)
        {
            result[i][j] = num;
            ++num;
            switch (dir)
            {
                case 1:
                    ++j;
                    if (j == n || result[i][j] != -1)
                    {
                        dir = 2;
                        --j;
                        ++i;
                    }
                    break;
                case 2:
                    ++i;
                    if ( i == n || result[i][j] != -1)
                    {
                        dir = 3;
                        --i;
                        --j;
                    }
                    break;
                case 3:
                    --j;
                    if (j < 0 || result[i][j] != -1)
                    {
                        dir = 4;
                        ++j;
                        --i;
                    }
                    break;
                case 4:
                    --i;
                    if (i < 0 || result[i][j] != -1)
                    {
                        dir = 1;
                        ++i;
                        ++j;
                    }
                    break;
            }
        }
        
        return result;
    }
};
