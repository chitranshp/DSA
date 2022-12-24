// https://leetcode.com/problems/domino-and-tromino-tiling/

class Solution {
public:
    int numTilings(int n) 
    {
        int mod = 1e9 + 7;
        vector<long long> dp(n + 1, 0);

        if(n == 0 || n == 1)
            return 1;

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++)
        {
            dp[i] = 2 * dp[i - 1] + dp[i - 3];
            dp[i] %= mod;
        }
            

        return dp[n];
    }
};
