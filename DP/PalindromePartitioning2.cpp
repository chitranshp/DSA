// https://leetcode.com/problems/palindrome-partitioning-ii/

/*
In PalindromePartitioning - 1, we were supposed to give all possible palindrome partitions that can be made on the given string.
To generate all possible partitions, we have no other option but to use recursion along with backtracking for optimization. But the time complexity will remain Exponential.

We will use a similar approach i.e. DFS, but instead of generating all partitions we will count the number of ways this is possible.
No need to maintain an extra subset to keep track of all partitions.

TC - O(2 ^ n)
SC - O(n)
*/

class Solution {
public:
    bool isPalindrome(string &s, int beg, int end) 
    {
        while(beg < end)
        {
            if(s[beg++] != s[end--])
                return false;
        }

        return true;
    }

    int generatePartitions(string &s, int index)
    {
        if(index == s.size())
            return 0;

        int mincost = INT_MAX;
        for(int i = index; i < s.size(); i++)
        {
            if(isPalindrome(s, index, i) == true)
            {
                int cost = 1 + generatePartitions(s, i + 1);
                mincost = min(cost, mincost);
            }
            //else if palindrome is not formed from substring(index, i), we will increment i by 1 and check for the new substring
            // If i == s.size(), we will return mincost which will be equal to INT_MAX;
            // Ex. ba != palindrome
            // Next bab == palindrome
            // Update cost by 1 for partition "bab" and solve genpartition(s, i + 1)
        }

        return mincost;
    }

    int minCut(string s) 
    {
        int n = s.size();

        // For a string "abc", we are creating a partition at 'a', then 2nd one at 'b' both of which are valid.
        // But it will do another extra partition after 'c', which is not required and extra.
        // Therefore, we will subtract 1 from the final answer
        return generatePartitions(s, 0) - 1;
    }
};

/*
dp[i] represents the minimum number of partitions that can be done from ith index till n.
dp[0] will store our final answer.

TC - O(n * n * n) i.e. There is another for loop involved and another O(n) for checking palindrome
SC - O(n) + O(n)
*/

class Solution {
public:
    bool isPalindrome(string &s, int beg, int end) 
    {
        while(beg < end)
        {
            if(s[beg++] != s[end--])
                return false;
        }

        return true;
    }

    int generatePartitions(string &s, int index, vector<int> &dp)
    {
        if(index == s.size())
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int mincost = INT_MAX;
        for(int i = index; i < s.size(); i++)
        {
            if(isPalindrome(s, index, i) == true)
            {
                int cost = 1 + generatePartitions(s, i + 1, dp);
                mincost = min(cost, mincost);
            }
        }

        return dp[index] = mincost;
    }

    int minCut(string s) 
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return generatePartitions(s, 0, dp) - 1;
    }
};

/*
TC - O(n * n * n)
SC - O(n)
*/

class Solution {
public:
    bool isPalindrome(string &s, int beg, int end) 
    {
        while(beg < end)
        {
            if(s[beg++] != s[end--])
                return false;
        }

        return true;
    }

    int minCut(string s) 
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for(int index = n - 1; index >= 0; index--)
        {
            int mincost = INT_MAX;
            for(int i = index; i < s.size(); i++)
            {
                if(isPalindrome(s, index, i) == true)
                {
                    int cost = 1 + dp[i + 1];
                    mincost = min(cost, mincost);
                }
            }

            dp[index] = mincost;
        }

        return dp[0] - 1;
    }
};

/* 
Further optimization:
Instead of checking for palindrome, we can use another table(dp) to store the palindrome values for entire string 
as part of preprcoessing.
TC - O(n * n) + O(n * n)
SC - O(n) + O(n * n)
*/

class Solution {
public:
    void isPalindrome(string &s, vector<vector<int>> &table) 
    {
        //We are going right to left, so that we can fill the table at same time and use it in subsequent iterations.
        // If we go left to right for 'i'. Intermediate cells will get used before getting updated. ex. "abbab"
        // Here dp[1][2] will be used for calculating dp[0][3] which will contain 'false' as part of initialization at that point of time
        // s[i] is the starting of substring
        for(int i = s.size() - 1; i >= 0; i--) 
        {
            // s[j] is the ending char of the substring
            for(int j = i; j < s.size(); j++)
            {
                // j - i <= 2, means either if substring is empty has one character or 2 chars, provided that s[i] == s[j] is verified as true as part of first condition
                if(s[i] == s[j] && (j - i <= 2 || table[i + 1][j - 1] == 1))
                    table[i][j] = 1;
                    
                /*
                Following can be also written as
                if(i == j)      // Has only one char.
                    table[i][j] = 1;     
                else if(s[i] == s[j] && j - i <= 2)  //Only 2 chars and both are equal or 3 chars with first and 3rd char being equal(2nd char doesnt matter then)
                    table[i][j] = 1
                else if(s[i] == s[j]) //First and last char being equal
                    table[i][j] = table[i + 1][j - 1] // If the string in between i & j(excluding i and j) is palindrome then true. ex. ababa  if i is at 'a' and j is at 'a' (last). The substring s[i..j] is palindrome if s[i + 1 ... j - 1] i.e. 'bab' is palindrome. (here s[i] is equal to s[j])
                */

                /*
                // Handled as part of initialization
                else
                    table[i][j] = false;
                */
            }
        }
    }

    int minCut(string s) 
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        vector<vector<int>> table(n, vector<int> (n, 0));

        isPalindrome(s, table);

        for(int index = n - 1; index >= 0; index--)
        {
            int mincost = INT_MAX;
            for(int i = index; i < s.size(); i++)
            {
                if(table[index][i] == 1)
                {
                    int cost = 1 + dp[i + 1];
                    mincost = min(cost, mincost);
                }
            }

            dp[index] = mincost;
        }

        return dp[0] - 1;
    }
};