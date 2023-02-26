// https://leetcode.com/problems/cherry-pickup-ii/submissions/905377332/
// https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885

class Solution {
public:


// This problem has a fixed starting point and a variable ending point.

//If we find the path for alice and bob separately, it will be tedious to track the path and trace it to remove the common cells from bob's path.
//Therefore, we will be trying to find the best path and chocolates for both of them together.

/*
Instead of having two separate variables to track row, we can use one common one. As both will move one step at each step and we are calculating path of both of them together.

Now, at each cell alice can take 3 different steps and at the same time bob can also take 3 different steps.
So, for us at each step there will be 3 * 3 = 9 path combination we have to explore to get our result.
     alice   Change in col value          bob          Change in col value
     down               +0               left                -1
     down               +0               right               +1
     down               +0               down                +0
     left               -1               right               +1
     left               -1               down                +0
     left               -1               left                -1
     right              +1               down                +0
     right              +1               left                -1
     right              +1               right               +1


     At max alice and bob will travel through n rows(1 cell on each row) each. And at each cell they will have three options.
     Therefore TC = O(3 ^ n * 3 ^ n) with Recursion
               TC = O((m * n * n) * 9) Here 9 is multiplied due to the internal loop which is of O(9).
                SC = O(n) (For stack)

*/

//dp[r][c1][c2] represents the number of chocolates alice and bob can together collect if from their respective starting points alice is now at [r][c1] and bob is at now [r][c2].

    int helper(vector<vector<int>>& grid, int r, int c1, int c2, vector<vector<vector<int>>> &dp)
    {
        if(c1 < 0 || c2 < 0 || c1 >= grid[0].size() || c2 >= grid[0].size())
            return -1e9;

        if(r == grid.size() - 1)
        {
            if(c1 == c2)
                return grid[r][c1];
            else
                return grid[r][c1] + grid[r][c2];
        }

        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int maxi = INT_MIN, total = grid[r][c1];
        
        if(c1 != c2)
            total += grid[r][c2];

        for(int dc1 = -1; dc1 <= 1; dc1++)
            for(int dc2 = -1; dc2 <= 1; dc2++)
                maxi = max(maxi, total + helper(grid, r + 1, c1 + dc1, c2 + dc2, dp));

        return dp[r][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));
        return helper(grid, 0, 0, n - 1, dp);
    }
};
