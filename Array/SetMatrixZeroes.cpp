//https://leetcode.com/problems/set-matrix-zeroes/

/* This is O(m + n) solution. */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> r(rows, -1);
        vector<int> c(cols, -1);
        
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(matrix[i][j] == 0)
                {
                    r[i] = 0;
                    c[j] = 0;
                }
        
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(r[i] == 0 || c[j] == 0)
                {
                    matrix[i][j] = 0;
                }
    }
};