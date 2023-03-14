// https://leetcode.com/problems/longest-common-subsequence/description/

/*
Recursion
TC - O()
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