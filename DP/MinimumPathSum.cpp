// https://leetcode.com/problems/minimum-path-sum/

/*
Memoization
TC - O(n * m)
SC - O(n * m) + O(n + m)
*/
class Solution {
public:
    unsigned int helper(vector<vector<int>>& grid, int r, int c, vector<vector<int>> &dp)
    {
        if(r < 0 || c < 0)
            return INT_MAX;
        if(r == 0 && c == 0)
            return grid[r][c];

        if(dp[r][c] != -1)
            return dp[r][c];

        unsigned int up = 0, left = 0;      
        up = grid[r][c] + helper(grid, r - 1, c, dp);
        left = grid[r][c] + helper(grid, r, c - 1, dp);
        return dp[r][c] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int gsum = INT_MAX, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(grid, m - 1, n - 1, dp);
    }
};

/* 
Tabulation - BottomUp DP 
TC - O(n * m)
SC - O(n * m)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else
                {
                    unsigned int up = INT_MAX, left = INT_MAX;
                    if(i > 0)
                        up = grid[i][j] + dp[i - 1][j];
                    if(j > 0)
                        left = grid[i][j] + dp[i][j - 1];

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

/* 
SpaceOptimization 
TC - O(n * m)
SC - O(n) + O(n)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        
        vector<int> prev(n, 0), curr(n, 0);
        prev[0] = grid[0][0];

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                    curr[0] = grid[i][j];
                else
                {
                    unsigned int up = INT_MAX, left = INT_MAX;
                    if(i > 0)
                        up = grid[i][j] + prev[j];
                    if(j > 0)
                        left = grid[i][j] + curr[j - 1];

                    curr[j] = min(up, left);
                }
            }

            prev = curr;
        }
        return prev[n - 1];
    }
};

/*
FurtherSpaceOptimization
TC - O(n * m)
SC - O(n)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                    dp[0] = grid[i][j];
                else
                {
                    unsigned int up = INT_MAX, left = INT_MAX;
                    if(i > 0)
                        up = grid[i][j] + dp[j];
                    if(j > 0)
                        left = grid[i][j] + dp[j - 1];

                    dp[j] = min(up, left);
                }
            }
        }
        return dp[n - 1];
    }
};
