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
