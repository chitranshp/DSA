// https://leetcode.com/problems/longest-common-subsequence/description/

/*
Recursion
TC - Exponential(2 ^ m + 2 ^ n).
SC - O(m + n) Stack space for worst case
*/

class Solution {
public:
    int helper(string& text1, string& text2, int m, int n)
    {
        //End of string is reached.
        if(m < 0 || n < 0)
        {
            return 0;
        }

        if(text1[m] == text2[n])
            return 1 + helper(text1, text2, m - 1, n - 1);
        else
            return max(helper(text1, text2, m - 1, n), helper(text1, text2, m, n - 1));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {   
        return helper(text1, text2, text1.size() - 1, text2.size() - 1);   
    }
};

/*
Memoization
Here dp[i][j] represents the length of longest subsequence till index 'i' in string1 and index 'j' in string2.
dp[i][j] = 0 if i < 0 or j < 0
           1 if s1[i] is equal to s2[j]
           max(f(i - 1, j), f(i, j - 1)) if s1[i] != s2[j]

dp[i][j] represents LCS of strings s1[0...i] and s2[0....j]

TC - O(m * n) 
SC - O(m * n) + O(m + n)
*/

class Solution {
public:
    int helper(string& text1, string& text2, int m, int n, vector<vector<int>> &dp)
    {
        if(m < 0 || n < 0)
        {
            return 0;
        }

        if(dp[m][n] != -1)
            return dp[m][n];

        if(text1[m] == text2[n])
            return dp[m][n] = 1 + helper(text1, text2, m - 1, n - 1, dp);
        else
            return dp[m][n] = max(helper(text1, text2, m - 1, n, dp), helper(text1, text2, m, n - 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {   
        vector<vector<int>> dp(string1.size(), vector<int> (string2.size(), -1));
        return helper(text1, text2, text1.size() - 1, text2.size() - 1, dp);   
    }
};

/*
Tabulation - Our base case was if(i < 0 || j < 0) which can also be written as i == -1 || j == -1.
To include case where i or j are -1, we will shift the index by one towards right. This means each index 'i' represents i - 1 in 0 - based indexing.

New base case will be 
if(i == 0 || j == 0)
    return 0;
TC - O(n * m)
SC - O(n * m)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {   
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        for(int i = 0; i <= m; i++)
            dp[i][0] = 0;

        for(int j = 0; j <= n; j++)
            dp[0][j] = 0;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];   
    }
};