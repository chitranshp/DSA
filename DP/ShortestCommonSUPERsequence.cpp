// https://leetcode.com/problems/shortest-common-supersequence/

/*
Supersequence - Containing both strings as subsequences
Length of this will be equal to len(s1) + len(s2) - len(lcs(s1, s2))

Ex. 'abac' and 'cab'. Here LCS  is 'ab'.
Shortest common supersequence will be 'cabac'. The trick is to include the subsequence which makes up LCS only once.
                                     0   1   2
                                     0   0   0
                                     c   a   b
                         0   0   a   0   1   1
                         1   0   b   0   1   2
                         2   0   a   0   1   2
                         3   0   c   1   1   2

We will use the similar logic as printing the LCS. 
We will backtrack along the LCS and store characters in reverse order. And at the end, we will just reverse the string formed before returning it.
There will be two cases:
1. When s1[i - 1] == s2[j - 1]
    Include that character only once and decrement i and j both.

2. When both are unequal, we will have to still backtrack along the LCS path as we need it too for our answer.
   So, we will store that character, which is being pointed currently by the index, which we are going to decrement. 
   The corresponding character in other string can be taken in next iteration as we will be decrementing only one index not both.

There may be a case that after the loop is terminated either i > 0 or j > 0 as loop condition will be (i > 0 && j > 0)
Therefore, run another while loop to store remaining characters in our resultant string. 

TC - O(M * N)
SC - O(M * N)
*/

class Solution {
public:
    void lcs(string& s1, string& s2, vector<vector<int>> &dp)   //O(n * n)
    {
        int m = s1.size(), n = s2.size();

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string shortestCommonSupersequence(string str1, string str2) 
    {
        vector<vector<int>> dp(str1.size() + 1, vector<int> (str2.size() + 1, 0));
        lcs(str1, str2, dp);

        string ans = "";
        int i = str1.size(), j = str2.size();

        while(i > 0 && j > 0)  //O(m + n)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else if(dp[i - 1][j] >= dp[i][j - 1])
            {
                ans += str1[i - 1];
                i--;
            }
            else
            {
                ans += str2[j - 1];
                j--;
            }
        }

        //Only one of these two loops will run at most.
        while(i > 0)
        {
            ans += str1[i - 1];        //If we put str1[i] here, one character will be written twice.
            i--;
        }
      
        while(j > 0)
        {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());    //O(N)
        return ans;
    }
};