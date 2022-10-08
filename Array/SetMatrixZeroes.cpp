//https://leetcode.com/problems/set-matrix-zeroes/

/* This is O(mn) TC and O(m + n) SC solution. */

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


//Optimal Solution with O(m * n) T.C. and O(1) S.C.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size(), cols = matrix[0].size();
        int colZero = 1;
        
        for(int i = 0; i < rows; i++)
        {
            if(matrix[i][0] == 0)                   //Handling 1st(0th) column
                colZero = 0;
            for(int j = 1; j < cols; j++)           //Skipping 1st(0th) column
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = rows - 1; i >= 0; i--)
        {
            for(int j = cols - 1; j >= 1; j--)         //We will use colZero for setting 0th column values
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            
            if(colZero == 0)                        //Setting values for 0th column
                matrix[i][0] = 0;
        }
    }
};