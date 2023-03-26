// https://leetcode.com/problems/regular-expression-matching/

/*
Recursion
TC - Exponential
SC - O(n + m)
*/

class Solution {
public:
    bool helper(string &s1, string &s2, int i, int j)
    {
        if(i < 0 && j < 0)
            return true;
        //Pattern is exhausted
        if(j < 0 && i >= 0)
            return false;
        //S1 is exhausted but pattern still has elements left to match. Means there is an empty string "" s1 and a pattern in s2. The only pattern which will match with empty string is "X*". *(Here X can be '.' or any other alphabet). If '*' is the 2nd last element, we can still call it match as it will match with 0 or more chars of previous element eventhough our s1 is empty.
        if(i < 0 && s2[j] == '*')
            return helper(s1, s2, i, j - 2);    //If j - 2 == -1, then first base condition will trigger and written true. If j - 2>= 0 and s2[j - 2] != '*' next base condition will return false.
        
        if(i < 0 || j < 0)  //If one of them is still empty at this point and other one has still some elements left
            return false;

        if(s1[i] == s2[j] || s2[j] == '.')
            return helper(s1, s2, i - 1, j - 1);
        else if(s2[j] == '*')
        {
            //Matches zero or more preceding character, if current char in s1 is matching preceding char of '*' in s2.
            if(s1[i] == s2[j - 1] || s2[j - 1] == '.')
            {
                //Matches zero preceding character
                bool op1 = helper(s1, s2, i, j - 2);  //Skip '*' and it's preceding character.  
                bool op2 = helper(s1, s2, i - 1, j);  //Match one character in s1 and decrement i by 1 to check for next char in s1. Notice 'j' is used in call which is pointing to '*'. So, for next(preceding) character in s1, we will be checking this again.
                return op1 || op2;
            }
            //Zero match is found for preceding char of s2. Skip '*' and it's preceding char.
            else
            {
                return helper(s1, s2, i, j - 2);
            }
        }
        else
            return false;
    }
    bool isMatch(string s, string p) {
        return helper(s, p, s.size() - 1, p.size() - 1);
    }
};

/*
Memoization
TC - O(m * n)
SC - O(m * n) + O(m + n)
*/

class Solution {
public:
    bool helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0)
            return true;
        //Pattern is exhausted
        if(j < 0 && i >= 0)
            return false;
        //S1 is exhausted but pattern still has elements left to match. Means there is an empty string "" s1 and a pattern in s2. The only pattern which will match with empty string is "X*". *(Here X can be '.' or any other alphabet). If '*' is the 2nd last element, we can still call it match as it will match with 0 or more chars of previous element eventhough our s1 is empty.
        if(i < 0 && s2[j] == '*')
            return helper(s1, s2, i, j - 2, dp);    //If j - 2 == -1, then first base condition will trigger and written true. If j - 2>= 0 and s2[j - 2] != '*' next base condition will return false.
        
        if(i < 0 || j < 0)  //If one of them is empty and other one has still some elements left
            return false;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j] || s2[j] == '.')
            return dp[i][j] = helper(s1, s2, i - 1, j - 1, dp);
        else if(s2[j] == '*')
        {
            //Matches zero or more preceding character, if current char in s1 is matching preceding char of '*' in s2.
            if(s1[i] == s2[j - 1] || s2[j - 1] == '.')
            {
                //Matches zero preceding character
                bool op1 = helper(s1, s2, i, j - 2, dp);  //Skip '*' and it's preceding character.  
                bool op2 = helper(s1, s2, i - 1, j, dp);  //Match one character in s1 and decrement i by 1 to check for next char in s1. Notice 'j' is used in call which is pointing to '*'. So, for next(preceding) character in s1, we will be checking this again.
                return dp[i][j] = op1 || op2;
            }
            //Zero match is found for preceding char of s2. Skip '*' and it's preceding char.
            else
            {
                return dp[i][j] = helper(s1, s2, i, j - 2, dp);
            }
        }
        else
            return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(s, p, s.size() - 1, p.size() - 1, dp);
    }
};

/*
Tabulation
TC - O(n * m)
SC - O(n * m)
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));

        dp[0][0] = true;

        for(int i = 1; i <= m; i++)
            dp[i][0] = false;

        //When s1 is empty but s2 has some non empty pattern. Only true if s2 is "X*"
        for(int j = 1; j <= n; j++)
            if(p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
            else
                dp[0][j] = false;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
               if(s[i - 1] == p[j - 1] || p[j - 1] == '.') 
                dp[i][j] = dp[i - 1][j - 1];
               else if(p[j - 1] == '*')
               {
                    if(s[i - 1] == p[j - 2] || p[j - 2] == '.')
                    {
                        //Matches zero preceding character
                        bool op1 = dp[i][j - 2];
                        bool op2 = dp[i - 1][j];
                        dp[i][j] = op1 || op2;
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
                else
                    dp[i][j] = false;
            }
        }

        return dp[m][n];
    }
};

/*
SpaceOptimization
TC - O(n * m)
SC - O(n) + O(n)
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> prev(n + 1, false), curr(n + 1, false);

        prev[0] = true;

        //When s1 is empty but s2 has some non empty pattern. Only true if s2 is "X*"
        for(int j = 1; j <= n; j++)
            if(p[j - 1] == '*')
                prev[j] = prev[j - 2];
            else
                prev[j] = false;

        for(int i = 1; i <= m; i++)
        {
            curr[0] = false;
            for(int j = 1; j <= n; j++)
            {
               if(s[i - 1] == p[j - 1] || p[j - 1] == '.') 
                curr[j] = prev[j - 1];
               else if(p[j - 1] == '*')
               {
                    if(s[i - 1] == p[j - 2] || p[j - 2] == '.')
                    {
                        //Matches zero preceding character
                        bool op1 = curr[j - 2];
                        bool op2 = prev[j];
                        curr[j] = op1 || op2;
                    }
                    else
                    {
                        curr[j] = curr[j - 2];
                    }
                }
                else
                    curr[j] = false;
            }

            prev = curr;
        }
        
        return prev[n];
    }
};