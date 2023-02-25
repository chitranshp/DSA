// https://leetcode.com/problems/minimum-falling-path-sum/description/

/* 
Recursion
*/

class Solution {
public:
    int helper(vector<vector<int>> &matrix, int r, int c)
    {
        if(c < 0 || c >= matrix[0].size())
            return 1e9;

        //Base Case
        if(r == 0)      //Return value indexed by r and c, if it's first row. 
            return matrix[r][c];
        
        int down = matrix[r][c] + helper(matrix, r - 1, c);
        int left = matrix[r][c] + helper(matrix, r - 1, c - 1);
        int right = matrix[r][c] + helper(matrix, r - 1, c + 1);

        return min(left, min(down, right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int res = INT_MAX, m = matrix.size();
        
        for(int i = 0; i < matrix[0].size(); i++)
            res = min(res, helper(matrix, m - 1, i));

        return res;
    }
};

/*
Memoization - TopDown DP
*/

class Solution {
public:
    int helper(vector<vector<int>> &matrix, int r, int c, vector<vector<int>> &dp)
    {
        if(c < 0 || c >= matrix[0].size())
            return 1e9;

        //Base Case
        if(r == 0)      //Return value indexed by r and c, if it's first row. 
            return matrix[r][c];

        if(dp[r][c] != -1)
            return dp[r][c];
        
        int down = matrix[r][c] + helper(matrix, r - 1, c, dp);
        int left = matrix[r][c] + helper(matrix, r - 1, c - 1, dp);
        int right = matrix[r][c] + helper(matrix, r - 1, c + 1, dp);

        return dp[r][c] = min(left, min(down, right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int res = INT_MAX, m = matrix.size();
        vector<vector<int>> dp(m, vector<int> (m, -1));
      
        for(int i = 0; i < matrix[0].size(); i++)
            res = min(res, helper(matrix, m - 1, i, dp));

        return res;
    }
};
