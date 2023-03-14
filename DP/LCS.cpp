// https://leetcode.com/problems/longest-common-subsequence/description/

/*
Recursion
TC - Exponential.
SC - O(m + n) Stack space for worst case
*/

class Solution {
public:
    int helper(string& text1, string& text2, int m, int n)
    {
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
Tabulation
TC - O(n * m)
SC - O(n * m)
*/

