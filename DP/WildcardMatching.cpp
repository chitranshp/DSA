// https://leetcode.com/problems/wildcard-matching/

/*
Recursion
TC - Exponential
SC - O(n + m)
*/
class Solution {
public:
    //Return true if all remaining characters in pattern string are '*' else returns false.
    bool checkallstars(string& p, int n)
    {
        for(int index = 0; index <= n; index++)
            if(p[index] != '*')
                return false;

        return true;
    }

    bool helper(string &s1, string &s2, int i, int j)
    {
        //Both the strings get exhausted. 
        if(i < 0 && j < 0)  
            return true;

        //s2(Pattern) gets exhausted. But the other string is not exhausted. This means there is still some sequence which was not covered in pattern. Therefore, return false.
        if(j < 0 && i >= 0)
            return false;

        //s1 is exhausted and is empty. But pattern still has some characters left. In this case only time when it will be true is when pattern is entirely made up of "*"(* will match any sequence of 0 or more in length.) Else, if pattern contains any other character it does not match. (In simple words, the only pattern which matches an empty string will be pattern made up of "*" entirely).
        if(i < 0 && j >= 0)
            return checkallstars(s2, j);

        if(s1[i] == s2[j] || s2[j] == '?')  //'?' matches with any one character
            return helper(s1, s2, i - 1, j - 1);
        else if(s2[j] == '*')   // '*' can match with any sequence with 0 or more characters.
        {
            bool op1 = helper(s1, s2, i, j - 1);    // * does not match with current character. In other words matches a sequence made up of 0 characters.
            bool op2 = helper(s1, s2, i - 1, j);    // * matches with 1(current) character and recursively check for next character(1 or more characters.)
            
            return op1 || op2;
        }
        else
            return false;
        
    }
    bool isMatch(string s, string p) 
    {
        return helper(s, p, s.size() - 1, p.size() - 1);
    }
};

/*
Memoization
TC - O(n * m)
SC - O(n * m) + O(n + m)
*/

class Solution {
public:

    //Return true if all remaining characters in pattern string are '*' else returns false.
    bool checkallstars(string& p, int n)
    {
        for(int index = 0; index <= n; index++)
            if(p[index] != '*')
                return false;

        return true;
    }

    bool helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        //Both the strings get exhausted. 
        if(i < 0 && j < 0)  
            return true;

        //s2(Pattern) gets exhausted. But the other string is not exhausted. This means there is still some sequence which was not covered in pattern. Therefore, return false.
        if(j < 0 && i >= 0)
            return false;

        //s1 is exhausted and is empty. But pattern still has some characters left. In this case only time when it will be true is when pattern is entirely made up of "*"(* will match any sequence of 0 or more in length.) Else, if pattern contains any other character it does not match. (In simple words, the only pattern which matches an empty string will be pattern made up of "*" entirely).
        if(i < 0 && j >= 0)
            return checkallstars(s2, j);

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j] || s2[j] == '?')  //'?' matches with any one character
            return dp[i][j] = helper(s1, s2, i - 1, j - 1, dp);
        else if(s2[j] == '*')   // '*' can match with any sequence with 0 or more characters.
        {
            bool op1 = helper(s1, s2, i, j - 1, dp);    // * does not match with current character. In other words matches a sequence made up of 0 characters.
            bool op2 = helper(s1, s2, i - 1, j, dp);    // * matches with 1(current) character and recursively check for next character(1 or more characters.)
            
            return dp[i][j] = op1 || op2;
        }
        else
            return dp[i][j] = false;
        
    }
    bool isMatch(string s, string p) 
    {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(s, p, s.size() - 1, p.size() - 1, dp);
    }
};

/*
Tabulation
TC - O(m * n)
SC - O(m * n)
*/

class Solution {
public:

    //Return true if all remaining characters in pattern string are '*' else returns false.
    bool checkallstars(string& p, int n)
    {
        // p[0 - 1] will be out of bound. Index is using 1 - based indexing
        for(int index = 1; index <= n; index++)
            if(p[index - 1] != '*')
                return false;

        return true;
    }

    bool isMatch(string s, string p) 
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));

        //Both i and j are based on 1 - based indexing whereas s and p are using 0 - based indexing. So, whenver we are using i and j to get corresponding characters from s and p, we will subtract 1 to get corresponding character using 0 - based indexing.
        for(int i = 1; i <= m; i++)
            dp[i][0] = false;

        for(int j = 1; j <= n; j++)
            dp[0][j] = checkallstars(p, j);     //dp[i][j] translates to s[0 .... i - 1] and p[0....j - 1]. 

        dp[0][0] = true;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
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

    //Return true if all remaining characters in pattern string are '*' else returns false.
    bool checkallstars(string& p, int n)
    {
        // p[0 - 1] will be out of bound. Index is using 1 - based indexing
        for(int index = 1; index <= n; index++)
            if(p[index - 1] != '*')
                return false;

        return true;
    }

    bool isMatch(string s, string p) 
    {
        int m = s.size(), n = p.size();
        vector<bool> prev(n + 1, false), curr(n + 1, false);

        //Both i and j are based on 1 - based indexing whereas s and p are using 0 - based indexing. So, whenver we are using i and j to get corresponding characters from s and p, we will subtract 1 to get corresponding character using 0 - based indexing.
        for(int j = 1; j <= n; j++)
            prev[j] = checkallstars(p, j);     //dp[i][j] translates to s[i - 1] and p[j - 1]. 

        prev[0] = true;

        for(int i = 1; i <= m; i++)
        {
            curr[0] = false;       
            for(int j = 1; j <= n; j++)
            {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else if(p[j - 1] == '*')
                    curr[j] = curr[j - 1] || prev[j];
                else
                    curr[j] = false;
            }

            prev = curr;
        }

        return prev[n];
    }
};