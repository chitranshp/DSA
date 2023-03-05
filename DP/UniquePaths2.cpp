//https://leetcode.com/problems/unique-paths-ii/description/
/*Recursion
TC - O(2 * (n * m))
SC - O((n - 1) * (m - 1))
*/
class Solution {
public:
    int helper(vector<vector<int>>&grid, int r, int c)
    {
        if(r < 0 || c < 0)
            return 0;
        if(grid[r][c] == 1)
            return 0;
        if(r == 0 && c == 0 && grid[r][c] == 0)
            return 1;

        int up = helper(grid, r - 1, c);
        int left = helper(grid, r, c - 1);
        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        return helper(obstacleGrid, m - 1, n - 1);
    }
};

/*
Memoization - TopDown DP
TC - O(n * m) At maximum, ther will n * m states in recursion
SC - O(n * m)For the dp vector + O((n- 1) * (m -1)) = O(n * m)
*/
class Solution {
public:
    int helper(vector<vector<int>>&grid, int r, int c, vector<vector<int>>& dp)
    {
        if(r < 0 || c < 0)
            return 0;
        if(grid[r][c] == 1) //Obstacle in path
            return 0;
        if(r == 0 && c == 0 && grid[r][c] == 0)   //Able to reach successfully
            return 1;

        if(dp[r][c] != -1)
            return dp[r][c];

        int up = helper(grid, r - 1, c, dp);
        int left = helper(grid, r, c - 1, dp);
        return dp[r][c] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(obstacleGrid, m - 1, n - 1, dp);
    }
};

/*
Tabulation
TC - O(n * m)
SC - O(n * m)
*/

class Solution {
public:
    int helper(vector<vector<int>>&grid, int r, int c, vector<vector<int>>& dp)
    {
        if(r < 0 || c < 0)
            return 0;
        if(grid[r][c] == 1)
            return 0;
        if(r == 0 && c == 0 && grid[r][c] == 0)
            return 1;

        if(dp[r][c] != -1)
            return dp[r][c];

        int up = helper(grid, r - 1, c, dp);
        int left = helper(grid, r, c - 1, dp);
        return dp[r][c] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));

        dp[0][0] = 1;   //Not needed, as we are again initialisng inside loop.

        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(obstacleGrid[r][c] == 1)
                {
                    dp[r][c] = 0;
                    continue;
                }

                if(r == 0 && c == 0)
                {
                    dp[r][c] = 1;
                    continue;           //So that, next if block is not executed for dp[0][0]. That will overwrite dp[0][0] values as 0.
                }

                int left = 0, up = 0;
                if(r >= 1)
                    up = dp[r - 1][c];
                if(c >= 1)
                    left = dp[r][c - 1];

                dp[r][c] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*
Space optimization - Same logic as UniquePaths.cpp
SC - O(n) + O(n)
*/
class Solution {
public:
    int helper(vector<vector<int>>&grid, int r, int c, vector<vector<int>>& dp)
    {
        if(r < 0 || c < 0)
            return 0;
        if(grid[r][c] == 1)
            return 0;
        if(r == 0 && c == 0 && grid[r][c] == 0)
            return 1;

        if(dp[r][c] != -1)
            return dp[r][c];

        int up = helper(grid, r - 1, c, dp);
        int left = helper(grid, r, c - 1, dp);
        return dp[r][c] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> prev(n, 0), curr(n, 0);

        prev[0] = 1;       //Base case

        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(obstacleGrid[r][c] == 1)
                {
                    curr[c] = 0;
                    continue;
                }

                if(r == 0 && c == 0)
                {
                    curr[c] = 1;
                    continue;           //So that, next if block is not executed for curr[0]. That will overwrite curr[0] values as 0.
                }

                int left = 0, up = 0;
                if(r >= 1)
                    up = prev[c];
                if(c >= 1)
                    left = curr[c - 1];

                curr[c] = up + left;
            }

            prev = curr;
        }
        return prev[n - 1];
    }
};
  
 /*
 Further Space optimization 
 SC - O(n)
 */
class Solution {
public:
    int helper(vector<vector<int>>&grid, int r, int c, vector<vector<int>>& dp)
    {
        if(r < 0 || c < 0)
            return 0;
        if(grid[r][c] == 1)
            return 0;
        if(r == 0 && c == 0 && grid[r][c] == 0)
            return 1;

        if(dp[r][c] != -1)
            return dp[r][c];

        int up = helper(grid, r - 1, c, dp);
        int left = helper(grid, r, c - 1, dp);
        return dp[r][c] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> prev(n, 0);

        prev[0] = 1;       //Base case(Not needed,as we are again doing it inside loop.

        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(obstacleGrid[r][c] == 1)
                {
                    prev[c] = 0;
                    continue;
                }

                if(r == 0 && c == 0)
                {
                    prev[c] = 1;
                    continue;           //So that, next if block is not executed for prev[0]. That will overwrite prev[0] values as 0.
                }

                int left = 0, up = 0;
                if(r >= 1)
                    up = prev[c];
                if(c >= 1)
                    left = prev[c - 1];

                prev[c] = up + left;
            }
        }
        return prev[n - 1];
    }
};
