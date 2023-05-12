// https://leetcode.com/problems/solving-questions-with-brainpower/

/*
This is a variation of House robber problem. We can use dynamic programming for this
TC - O(n)
SC - O(n) + O(n)
*/

class Solution {
public:
    long long helper(vector<vector<int>>& questions, int index, vector<long long int> &dp) 
    {
        if(index >= questions.size())
            return 0;

        if(dp[index] != -1)
            return dp[index];

        long long int pick = questions[index][0] + helper(questions, index + questions[index][1] + 1, dp);
        long long int notpick = helper(questions, index + 1, dp);

        return dp[index] = max(pick, notpick);
    }

    long long mostPoints(vector<vector<int>>& questions) 
    {
        vector<long long int> dp(questions.size(), -1);
        return helper(questions, 0, dp);
    }
};

/*
Tabulation
TC - O(n)
SC- O(n)
*/

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        vector<long long int> dp(questions.size() + 1, 0);
        int n = questions.size();

        for(int i = n - 1; i >= 0; i--)
        {
            long long int pick = questions[i][0];

            if(i + questions[i][1] + 1 < n)
                pick += dp[i + questions[i][1] + 1];

            long long int notpick = 0;
            if(i + 1 < n)
                notpick = dp[i + 1];

            dp[i] = max(pick, notpick);
        }

        return dp[0];
    }
};