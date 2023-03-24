// https://leetcode.com/problems/distinct-subsequences/

/*
s: babgbag             t: bag

How many distinct subsequences of s are equal to t?
This is a type of string matching problem. It does not follow any specific pattern. So, our only option is to find out all possible subsequences of s and count how many match t.
To try out all possible subsequences, we will use recursion first.

i -> s      j -> t
f(i, j) -> Number of subsequences of s[0...i] that are equal to t[0...j]

There will be two cases:
    Case 1: When s[i] != t[j]
    In this case, we dont have any other option. We can only check whether the next letter in s matches that letter indexed by j or not.
    i. e. If s[i] != t[j] => f(i - 1, j)
    
    0123456     012
    babgbag     bag
    Case 2: When s[i] == t[j]. (i = 6 and j = 2)
    We will check for f(i - 1, j - 1) ie whether 5th index in s matches with 1st index of t.

    But, we can see that there is another g in 's' at index 3. So, if we only check for f(i - 1, j - 1) we will fail to check for repeated characters in s.
    To counter this, we can also check for f(i - 1, j) i.e. Whether j th character of 't' occurs again somewhere and is part of another subsequence or not.
    
    if(s[i] == t[j])
        return f(i - 1, j - 1) + f(i - 1, j);

Base case:
1. If j's value is getting less than 0(-1 to be exact) this means that any subsequence of s has matched with the entire 't'.
Because we are only decrementing 'j' if there is a match. Therefore, this means one such subsequence is found. So, we will return 1.

2. If i's value is getting less than 0 this means that we have gone through entire string 's' and have not found such subsequence.
Therefore, we will return 0.

Note: There might be a case when i = -1 and j = -1, ie all characters of both strings are exhausted but we have found a match.
Therefore, to handle this case we will be writing the base case for j above the base case for i.

TC - Exponential
SC - O(m + n) 
*/

class Solution {
public:
    int helper(string &s, string &t, int i, int j)
    {
        if(j < 0)
            return 1;
        if(i < 0)
            return 0;
            
        if(s[i] == t[j])
            return helper(s, t, i - 1, j - 1) + helper(s, t, i - 1, j);
        else
            return helper(s, t, i - 1, j);
    }
    int numDistinct(string s, string t) 
    {
        return helper(s, t, s.size() - 1, t.size() - 1);
    }
};

/*
Memoization
TC - O(m * n)
SC - O(m * n) + O(m + n)
*/

class Solution {
public:
    int helper(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if(j < 0)
            return 1;
        if(i < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(s[i] == t[j])
            return dp[i][j] = helper(s, t, i - 1, j - 1, dp) + helper(s, t, i - 1, j, dp);
        else
            return dp[i][j] = helper(s, t, i - 1, j, dp);
    }
    int numDistinct(string s, string t) 
    {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(s, t, s.size() - 1, t.size() - 1, dp);
    }
};

/*
Tabulation
TC - O(m * n)
SC - O(m * n)
*/

class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int m = s.size(), n = t.size();
        //To counter for the base case i < 0 and j < 0, let's shift dp table by 1
        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int> (n + 1, 0));

        for(int i = 0; i <= m; i++)
            dp[i][0] = 1;

        /*
        for(int j = 1; j <= n; j++)     //j = 0, will wrongly overwrite dp[0][0] with 0.
            dp[0][j] = 0;
        */
       
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                // i and j are also shifted by 1 as they are iterating over dp.
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[m][n];
    }
};

/*
Space optimization - Each cell depends on immediate upper cell and it's immediate left upper diagonal cell.
Each row is dependent on it's previous row value only. No dependence on current row's value.
Therefore, we will fill from right to left and use only one row to store data for both previous and current row.
TC - O(m * n)
SC - O(n)
*/

class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int m = s.size(), n = t.size();
        //To counter for the base case i < 0 and j < 0, let's shift dp table by 1
        vector<unsigned int> dp(n + 1, 0);

        for(int i = 1; i <= m; i++)
        {
            dp[0] = 1;                  //dp[i][0] = 1 Base case
            for(int j = n; j >= 1; j--)
            {
                // i and j are also shifted by 1 as they are iterating over dp.
                if(s[i - 1] == t[j - 1])
                    dp[j] = dp[j - 1] + dp[j];
                else
                    dp[j] = dp[j];      //Redundant. Can be removed also.
            }
        }

        return dp[n];
    }
};