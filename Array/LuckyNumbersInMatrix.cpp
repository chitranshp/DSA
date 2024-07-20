// https://leetcode.com/problems/lucky-numbers-in-a-matrix/
// There will be only one such element atmost in a matrix. We can prove it using method of contradiction.
// TC - O(m * n)
// SC - O(m)

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), rowMin = INT_MAX;
        unordered_set<int> us;

        for(int i = 0; i < m; i++) 
        {
            rowMin = INT_MAX;
            for(int j = 0; j < n; j++) 
            {
                rowMin = min(rowMin, matrix[i][j]);
            }

            us.insert(rowMin);
        }

        int colMax = INT_MIN;
        for(int j = 0; j < n; j++) 
        {
            colMax = INT_MIN;
            for(int i = 0; i < m; i++)
            {
                colMax = max(colMax, matrix[i][j]);
            }

            if(us.count(colMax) != 0)
                return {colMax};
        }

        return lucky;
    }
};

// Approach 2: SC - O(1)
/*
                                        x    atleast(x+1) atleast(x+2)
                                        x-1       
                                        x-2

For columns, if x is the min ele in row 0 col0,that means that in other col the max element will be >= x+1 atleast. Whatever values are there in row2 & row1 for 
both columns. But the maximum will be >= x + 1. This means that x will be the minimum out of all max elements for each column.

Similarly, we can also prove that if x has to exist it will be the greatest of all min values for each row.
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int rowMinMax = INT_MIN;

        for(int i = 0; i < m; i++) 
        {
            int rowMin = INT_MAX;
            for(int j = 0; j < n; j++) 
            {
                rowMin = min(rowMin, matrix[i][j]);
            }

            rowMinMax = max(rowMinMax, rowMin);
        }

        int colMaxMin = INT_MAX;
        for(int j = 0; j < n; j++) 
        {
            int colMax = INT_MIN;
            for(int i = 0; i < m; i++)
            {
                colMax = max(colMax, matrix[i][j]);
            }

            colMaxMin = min(colMaxMin, colMax);
        }

        if(colMaxMin == rowMinMax)
            return {colMaxMin};

        return {};
    }
};
