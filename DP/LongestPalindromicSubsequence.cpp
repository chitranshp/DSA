// https://leetcode.com/problems/longest-palindromic-subsequence/

/*
    We can think of two approaches to solve this problem:
    First One:  
        Generate all subsequences (recursively or through powerset) (TC will be 2 ^ n)
        Check each subsequence if it is a palindrome
        Return the length of longest palindrome
    Total time complexity will be exponential.

    To reduce the time complexity we can approach this problem in another way.
    Second One:
        Make a second copy of original string and reverse it while keeping the original    string unchanged.
        Now, the problem is converted to finding the longest common subsequence(LCS) as any common subsequence between these 2 strings will be a palindrome.


    TC - O(n * n) + O(n)
    SC - O(n * n) and can be optimized to O(n) + O(n).
*/

class Solution {
public:
    //Bottom Up DP
    int lcs1(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0 + max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[m][n];
    }

    //Space optimized version.
    int lcs2(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = 0 + max(prev[j], curr[j - 1]);
            }

            prev = curr;
        }

        return prev[n];
    }

    int longestPalindromeSubseq(string s) 
    {
        string rev(s);
        reverse(rev.begin(), rev.end());    // O(n)
        
        return lcs2(s, rev);
    }
};