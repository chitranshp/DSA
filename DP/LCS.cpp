// https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:
    int helperfun(string &text1, string &text2, int m, int n, int dp[][1001])
    {
        if(m == 0 || n == 0)
            return 0;

        if(dp[m][n] != -1)
            return dp[m][n];

        if(text1[m - 1] == text2[n - 1])
        {
            dp[m][n] = 1 + helperfun(text1, text2, m - 1, n - 1, dp);
            return dp[m][n];
        }     
        else
        {
            return dp[m][n] = max(helperfun(text1, text2, m - 1, n, dp), helperfun(text1, text2, m, n - 1, dp));
        }
            
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));

        return helperfun(text1, text2, text1.size(), text2.size(), dp);
    }
};
