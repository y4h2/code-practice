/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

//与spiral matrix解法基本相同

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) 
    {
        vector<int> result;
        if (matrix.size() == 0 || matrix[0].size() == 0) return result;
        
        int i = 0, j = 0;
        int direct = 1;
        int limit = matrix.size() * matrix[0].size();
        
        while (1)
        {
            result.push_back(matrix[i][j]);
            if (result.size() == limit)
                break;
            matrix[i][j] = 0;
            switch(direct)
            {
                case 1:
                    ++j;
                    if (j == matrix[0].size() || matrix[i][j] == 0)
                    {
                        direct = 2;
                        --j;
                        ++i;
                    }
                    break;
                case 2:
                    ++i;
                    if (i == matrix.size() || matrix[i][j] == 0)
                    {
                        direct = 3;
                        --i;
                        --j;
                    }
                    break;
                case 3:
                    --j;
                    if (j < 0 || matrix[i][j] == 0)
                    {
                        direct = 4;
                        ++j;
                        --i;
                    }
                    break;
                case 4:
                    --i;
                    if (i < 0 || matrix[i][j] == 0)
                    {
                        direct = 1;
                        ++i;
                        ++j;
                    }
                    break;
            }
        }
        
        return result;
    }
};
