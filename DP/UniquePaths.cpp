// https://leetcode.com/problems/unique-paths/

/* 
Plain Recursion - At every step we have two options either go down or right. So, we will explore all options and add 1 whenever a path is leading to our desired ending.
TC - O(2 ^ (m * n)) 
SC - O(m + n) (Think of a L shaped path across the grid)
*/

class Solution {
public:
    int helper(int r, int c)
    {
        if(r == 0 && c == 0)
            return 1;
        else if(r < 0 || c < 0)
            return 0;

        int up = helper(r - 1, c);
        int left = helper(r, c - 1);

        return up + left;
    }
    int uniquePaths(int m, int n) 
    {
        return helper(m - 1, n - 1);
    }
};

/* 
Memoization - We observe that this problem has a lot of overlapping subproblems. So, using memoization to store results of repeating subproblems and reusing them
We will use a vector of vector of size (n * m) for this.
Total time complexity will be equal to the number of states ie O(n * m) as we will call f(0, 0), f(0, 1) to f(m - 1, n - 1) 
Space complexity will be O(n * m) + O(n + m) 

Another thing is if neither of r or c is less than 0 but one of them is equal to 0. We can just directly return 1. As the robot can only walk in two directions and if is in the last row or last column their is only 1 way it can reach the final square ie along that row or column only. 
We can make this is another base case.
*/

class Solution {
public:
    int helper(int r, int c, vector<vector<int>> &dp)
    {
        if(r == 0 && c == 0)
            return 1;
        else if(r < 0 || c < 0)
            return 0;

        if(dp[r][c] != -1)
            return dp[r][c];

        int up = helper(r - 1, c, dp);
        int left = helper(r, c - 1, dp);

        return dp[r][c] = up + left;
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, dp);
    }
};

/* 
Tabulation
TC - O(n * m) SC - O(n * m)
*/

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        //Initializing as 1 to help with base case. Rest values that are not covered with base case will be directly overwritten with correct values before being used for first time
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

/*
Space Optimization
TC - o(n * m) SC - O(n) + O(n)
*/

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<int> prev(n, 1);

        for(int i = 1; i < m; i++)
        {
            vector<int> curr(n, 1);
            for(int j = 1; j < n; j++)
            {
                //For further optimization, we can notice that curr is same as prev before being updated in current iteration.
                curr[j] = prev[j] + curr[j - 1];
            }
            
            prev = curr;
        }

        return prev[n - 1];
    }
};

/* 
Further Space optimization - Instead of two vectors of O(n) we will use only 1 vector of O(n)
TC - o(n * m) SC - O(n) + O(n)
*/

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<int> curr(n, 1);

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                curr[j] = curr[j] + curr[j - 1];
            }
        }

        return curr[n - 1];
    }
};

/*
Space can be further optimized to O(1), if we use principals of permutation and combination
Refer https://github.com/chitranshp/DSA/blob/main/Misc/UniquePaths.cpp
*/
