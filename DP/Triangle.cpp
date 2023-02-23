// https://leetcode.com/problems/triangle/

/* Recursion */

class Solution {
public:
    long int helper(vector<vector<int>> &arr, int r, int c)
    {
        if(r == arr.size() - 1)
            return arr[r][c];

        if(r >= arr.size() || c >= arr[0].size())
            return INT_MAX;

        long int a = arr[r][c] + helper(arr, r + 1, c);
        long int b = arr[r][c] + helper(arr, r + 1, c + 1);
        return min(a, b);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        return helper(triangle, 0, 0);    
    }
};
