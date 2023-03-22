// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/


//Approach 1:
/*
If we want to use tabulation instead of memoization, remember that we want to find dp[0][n] i.e. minimum insertions to make the string in between index 0 and index n palindrome [0, n)
TC - O(N * N) 
SC - O(N * N) + Stack space O(N)
*/
class Solution {
public:
    int helper(string &s, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        /* If characters at both ends are same, then we don't need to insert anything to make them palindrome for those 2 characters. */
        if(s[i] == s[j])
            return dp[i][j] = helper(s, i + 1, j - 1, dp);

        /* We won't be actually inserting the character. We are just counting the number of insertions we have to make */

        //We will have to insert 1 character at s[j] such that s[j] = s[i]. After that we will check for s[i + 1] and the original character at s[j] as we will also need to check for it.  
        int op1 = 1 + helper(s, i + 1, j, dp);

        //We will have to insert 1 character at s[i] such that s[i] = s[j]. After that we will check for s[j - 1] and the original character at s[i] as we will also need to check for it.  
        int op2 = 1 + helper(s, i, j - 1, dp);

        return dp[i][j] = min(op1, op2);
    }
    
    int minInsertions(string s) 
    {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
        return helper(s, 0, s.size() - 1, dp);
    }
};

/*
Approach 2: Find the longest palindromic subsequence and keep it intact. And for the remaining portion of the string, we can insert it in reverse again at the other side to make the whole string palindrome.
                Ex. codingninjas where longest palindrome is ingni.

                        codi ingni njas
                codi |sajn| ingni njas |idoc| will be the required palindrome made from codingninjas with minimum insertions.

        Number of minimum insertions = Total length of string - Length of longest pallindrome subsequence.
TC - O(N * N) 
SC - O(N) + O(N)
*/

class Solution {
public:
    int lcs(string &s1, string &s2)
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
                    curr[j] = max(curr[j - 1], prev[j]);
            }

            prev = curr;
        }

        return prev[n];
    }

    int LengthOflongestPalindromicSubseq(string& s)
    {
        string t(s);
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
    
    int minInsertions(string s) 
    {
        return s.size() - LengthOflongestPalindromicSubseq(s);
    }
};