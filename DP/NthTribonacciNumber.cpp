// https://leetcode.com/problems/n-th-tribonacci-number/submissions/888201157/

/*
class Solution {
public:
    //Bottom Up - Tabulation TC O(N) SC O(N)
    int tribonacci(int n) 
    {
        vector<int> dp(n + 1, -1);

        if(n <= 1)
            return n;
        else if(n == 2)
            return 1;

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        return dp[n];   
    }
};
*/

/*
class Solution {
public:
    //Top down - Memoization TC O(N) SC O(N) + O(N)
    int helper(vector<int>& dp, int index)
    {
        if(index == 1 || index == 2)
            return 1;

        if(index == 0)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        return dp[index] = helper(dp, index - 1) + helper(dp, index - 2) + helper(dp, index - 3);
    }
    int tribonacci(int n) 
    {
        vector<int> dp(n + 1, -1);

        return helper(dp, n);   
    }
};
*/
