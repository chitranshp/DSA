// https://leetcode.com/problems/triangle/

/* Recursion 
In first row there is 1 column, 2 in 2nd, 3 in 3rd and i in ith row.
So in total there will be 1+2+3+....+n states = O(n^2)
Total TC = O(2 ^ ( n ^ 2))
*/

class Solution {
public:
    int helper(vector<vector<int>> &triangle, int r, int c)
    {
        if(r == triangle.size() - 1)
            return triangle[r][c];

        /*
        //This case is not necessary because for given r and c, c and c + 1 will always be withing array range(As size of each row is 1 more than it's previous one). And for row we have previous if condition which won't allow r to grow out of array bound.
        if(r >= triangle.size() || c >= triangle[r].size())   //Size of each row is different
            return INT_MAX;
        */

        int down = triangle[r][c] + helper(triangle, r + 1, c);
        int diagonal = triangle[r][c] + helper(triangle, r + 1, c + 1);
        return min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        return helper(triangle, 0, 0);    
    }
};

/* Memoization */

class Solution {
public:
    int helper(vector<vector<int>> &triangle, int r, int c, vector<vector<int>> &dp)
    {
        if(r == triangle.size() - 1)
            return triangle[r][c];

        if(dp[r][c] != -1)
            return dp[r][c];

        int down = triangle[r][c] + helper(triangle, r + 1, c, dp);
        int diagonal = triangle[r][c] + helper(triangle, r + 1, c + 1, dp);
        return dp[r][c] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        return helper(triangle, 0, 0, dp);    
    }
};
