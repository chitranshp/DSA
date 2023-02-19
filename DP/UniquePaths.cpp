// https://leetcode.com/problems/unique-paths/

/* 
Plain Recursion - At every step we have two options either go down or right. So, we will explore all options and add 1 whenever a path is leading to our desired ending.
TC - O(2 ^ (m * n)) 
SC - O(m + n) (Think of a L shaped path across the grid)
*/

class Solution {
public:
    int helper(int m, int n, int r, int c)
    {
        if(r == 0 && c == 0)
            return 1;
        else if(r > m - 1 || c > n - 1 || r < 0 || c < 0)
            return 0;

        int up = helper(m, n, r - 1, c);
        int left = helper(m, n, r, c - 1);

        return up + left;
    }
    int uniquePaths(int m, int n) 
    {
        return helper(m, n, m - 1, n - 1);
    }
};

/* 
Memoization - We observe that this problem has a lot of overlapping subproblems. So, using memoization to store results of repeating subproblems and reusing them
We will use a vector of vector of size (n * m) for this.
Total time complexity will be equal to the number of states ie O(n * m) as we will call f(0, 0), f(0, 1) to f(m - 1, n - 1) 
Space complexity will be O(n * m) + O(n + m) 
*/

class Solution {
public:
    int helper(int m, int n, int r, int c, vector<vector<int>> &dp)
    {
        if(r == 0 && c == 0)
            return 1;
        else if(r > m - 1 || c > n - 1 || r < 0 || c < 0)
            return 0;

        if(dp[r][c] != -1)
            return dp[r][c];

        int up = helper(m, n, r - 1, c, dp);
        int left = helper(m, n, r, c - 1, dp);

        return dp[r][c] = up + left;
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m, n, m - 1, n - 1, dp);
    }
};
