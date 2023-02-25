// https://leetcode.com/problems/minimum-falling-path-sum/description/

/* 
Recursion - There is no fixed starting single point and ending point is also variable. We will have to explore all n starting points to get our answer.
For every point, we will explore 3 options(left, right, or top/bottom). And we will do that for all points along 1 column. Therefore time complexity will be around O(3 ^ n)
Total time complexity = O(n(3 ^ n)) as we are calling the recursion n times.
SC = O(n) 
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
TC - O(n * n)
SC - O(n * n) + O(n) 
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


/* 
Tabulation - We are simply filling the table row by row.
TC - O(n * n) + O(n) for finding the max/base case.
SC - O(n * n) 
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int res = INT_MAX, m = matrix.size();
        vector<vector<int>> dp(m, vector<int> (m, -1));
        
        //Base case
        for(int c = 0; c < m; c++)
            dp[0][c] = matrix[0][c];

        for(int r = 1; r < m; r++)
        {
            for(int c = 0; c < m; c++)
            {
                int down = 1e9, left = 1e9, right = 1e9;
                
                down = matrix[r][c] + dp[r - 1][c];
                if(c - 1 >= 0)
                    left = matrix[r][c] + dp[r - 1][c - 1];

                if(c + 1 <= m - 1)
                    right = matrix[r][c] + dp[r - 1][c + 1];

                dp[r][c] = min(left, min(down, right));
            }
        }

        for(int c = 0; c < m; c++)
            res = min(res, dp[m - 1][c]);

        return res;
    }
};

/*
Space Optimization - We don't need the whole table at any point of time. We just need the prev column and we need another DS to store the computed values for current run.
SC - O(N) + o(N)
*/

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int res = INT_MAX, m = matrix.size();
        vector<int> prev(m, 0), curr(m, 0);

        for(int c = 0; c < m; c++)
            prev[c] = matrix[0][c];

        for(int r = 1; r < m; r++)
        {
            for(int c = 0; c < m; c++)
            {
                int down = 1e9, left = 1e9, right = 1e9;
                
                down = matrix[r][c] + prev[c];
                if(c - 1 >= 0)
                    left = matrix[r][c] + prev[c - 1];

                if(c + 1 <= m - 1)
                    right = matrix[r][c] + prev[c + 1];

                curr[c] = min(left, min(down, right));
            }

            prev = curr;
        }

        for(int c = 0; c < m; c++)
            res = min(res, prev[c]);

        return res;
    }
};
