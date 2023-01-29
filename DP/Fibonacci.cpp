// https://leetcode.com/problems/fibonacci-number/submissions/887632776/

class Solution {
public:
    //Meomory Optimized version:- TC O(N) SC O(1).
    int fib(int n) 
    {
        if(n <= 1)
            return n;

        int first = 0, second = 1, third;

        for(int i = 2; i <= n; i++)
        {
            third = first + second;
            first = second;
            second = third;
        }

        return third;
    }
};

/*
class Solution {
public:
    //Tabulation(Bottom Up approach) - TC O(N) SC O(N) + O(N) for vector.
    int fib(int n) 
    {
        vector<int> dp(n + 1,  -1);
        if(n <= 1)
            return n;

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};
*/

/*
class Solution {
public:
    //Memoization(Top down recursion) - TC O(N) SC O(N) + O(N) for stack and for vector.
    int helper(int n, vector<int> &dp)
    {
        if(n <=  1)
            return n;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
    int fib(int n) 
    {

        vector<int> dp(n + 1,  -1);
        if(n <= 1)
            return n;

        helper(n, dp);
        return dp[n];
    }
};
*/
