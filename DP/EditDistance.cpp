// https://leetcode.com/problems/edit-distance/description/

/*
Recursion
If our question was limited to only inserting and deleting, we could have solved it in a similar fashion to  DP\MinNoOfInsertionAndDeletionToMakeStringsEqual.cpp
But since, we have three options here (insert, delete, replace), there is no uniformity across this question. So, we wil choose recursion for this.

Base cases:
          i  0 1 2 
             h o s r o s

    If j == -1, all characters of word2 are already formed in word1. So, delete all remaining characters in word1
    Number of such characters will be 1 + i = 1 + 2 = 3 characters (0 to i).  (If i = -1, it will return 0)
          j  -1
             "" r o s

            -1
         i  ""

If i == -1, this means that all characters in word1 are exhausted. But still some characters(-1 to word2.size()). 
We will just insert all remaining characters of word2 in word1. 
Such characters will be 1 + j = 1 + 2 = 3 characters.
             0 1 2
         j   r o s
TC - Exponential
SC - O(n + m)
*/

class Solution {
public:
    int helper(string &word1, string &word2, int i, int j)
    {
        //Whole word2 has been matched/formed in word1. But there might be still extra characters left in word1. We will just delete them. As both words are 0 indexed, adding 1 to it will give the number of words to be deleted in word1(All those words/indexes are yet to be travesrsed) 
        if(j < 0)       
            return i + 1;

        //We have reached the end of word1, but there are some words left in word2 which are yet to be matched. So, we will just insert all such characters.(Adding 1 to counter the 0 - based indexing)
        if(i < 0)
            return j + 1;

        //If both characters match then no operations need to be done, just check for the next characters.
        if(word1[i] == word2[j])
            return helper(word1, word2, i - 1, j - 1);
        else
        {
            /*
            We will have three options. We can
            Insert a character - We will obviously insert the same character as in word2 which gurantees a match. Therefore, j will be decremented but 'i' the original character at index 'i' will still be a part of word1. We still need to find a match or insert/delete/replace it.

            Replace a characer - Again, if we are replacing we will do it with the same corresponding character. Therefore, both indexes will be decremented.

            Delete a character - If we are deleting a character, we can just move to the next character in word1(But will still stand at the same character in word2), and see if it matches with the character in word2. We are deleting in word1, character in word2 will remain intact.
            */
            int op1 = 1 + helper(word1, word2, i, j - 1);   //Insert
            int op2 = 1 + helper(word1, word2, i - 1, j - 1); //Replace
            int op3 = 1 + helper(word1, word2, i - 1, j);   //Delete
            return min(op1, min(op2, op3));
        }
    }
    
    int minDistance(string word1, string word2) 
    {
        return helper(word1, word2, word1.size() - 1, word2.size() - 1);
    }
};

/*
Memoization
TC - O(n * m)
SC - O(n * m) + O(n + m)
*/

class Solution {
public:
    int helper(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
    {
        //Whole word2 has been matched/formed in word1. But there might be still extra characters left in word1. We will just delete them. As both words are 0 indexed, adding 1 to it will give the number of words to be deleted in word1(All those words/indexes are yet to be travesrsed) 
        if(j < 0)       
            return i + 1;

        //We have reached the end of word1, but there are some words left in word2 which are yet to be matched. So, we will just insert all such characters.(Adding 1 to counter the 0 - based indexing)
        if(i < 0)
            return j + 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        //If both characters match then no operations need to be done, just check for the next characters.
        if(word1[i] == word2[j])
            return dp[i][j] = helper(word1, word2, i - 1, j - 1, dp);
        else
        {
            /*
            We will have three options. We can
            Insert a character - We will obviously insert the same character as in word2 which gurantees a match. Therefore, j will be decremented but 'i' the original character at index 'i' will still be a part of word1. We still need to find a match or insert/delete/replace it.

            Replace a characer - Again, if we are replacing we will do it with the same corresponding character. Therefore, both indexes will be decremented.

            Delete a character - If we are deleting a character, we can just move to the next character in word1(But will still stand at the same character in word2), and see if it matches with the character in word2. We are deleting in word1, character in word2 will remain intact.
            */
            int op1 = 1 + helper(word1, word2, i, j - 1, dp);   //Insert
            int op2 = 1 + helper(word1, word2, i - 1, j - 1, dp); //Replace
            int op3 = 1 + helper(word1, word2, i - 1, j, dp);   //Delete
            return dp[i][j] = min(op1, min(op2, op3));
        }
    }
    
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1));
        return helper(word1, word2, word1.size() - 1, word2.size() - 1, dp);
    }
};

/*
Tabulation
TC - O(n * m)
SC - O(n * m)
*/

class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, 0));

        //To handle the -1 scenario, we will be converting table to 1 based indexing. 'i' actually represents 'i + 1'. Same is the case for 'j'.
        for(int i = 0; i <= m; i++)
            dp[i][0] = i;

        for(int j = 0; j <= n; j++)
            dp[0][j] = j;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j]));
                }
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
    int minDistance(string word1, string word2) 
    {
        int m = word1.size(), n = word2.size();
        //vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, 0));
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        //To handle the -1 scenario, we will be converting table to 1 based indexing. 'i' actually represents 'i + 1'. Same is the case for 'j'.
        for(int j = 0; j <= n; j++)
            prev[j] = j;

        for(int i = 1; i <= m; i++)
        {
            curr[0] = i;
            for(int j = 1; j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j - 1];
                else
                {
                    curr[j] = 1 + min(curr[j - 1], min(prev[j - 1], prev[j]));
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};