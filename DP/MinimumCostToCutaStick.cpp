// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

/*
With Plain recursion 
TC - O(n * n * n)   O(n ^ 2) to cover all the states and O(n) for the loop.
SC - O(n)

With Memoization(Recursion + DP)
TC - O(n ^ 3)
SC - O(n ^ 2) + O(n)
*/

class Solution {
public:
    int helper(vector<int>& cuts, int i, int j, vector<vector<int>> &dp) 
    {
        if(i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mincost = INT_MAX;
        for(int index = i; index <= j; index++)
        {
            int val = cuts[j + 1] - cuts[i - 1] + helper(cuts, i, index - 1, dp) + helper(cuts, index + 1, j, dp);
            mincost = min(val, mincost);
        }

        return dp[i][j] = mincost;
    }

    int minCost(int n, vector<int>& cuts) 
    {
        vector<vector<int>> dp(cuts.size() + 2, vector<int> (cuts.size() + 2, -1));
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        return helper(cuts, 1, cuts.size() - 2, dp);
    }
};

/*
Tabulation
TC - O(n ^ 3)
SC - O(n ^ 2)
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) 
    {
        vector<vector<int>> dp(cuts.size() + 2, vector<int> (cuts.size() + 2, 0));
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        for(int i = cuts.size() - 2; i >= 1; i--)
        {
            for(int j = 1; j <= cuts.size() - 2; j++)
            {
                if(i > j)
                    continue;       //dp[i][j] = 0 covered in initialization
                    
                int mincost = 1e8;
                for(int index = i; index <= j; index++)
                {
                    int val = cuts[j + 1] - cuts[i - 1] + dp[i][index - 1] + dp[index + 1][j];
                    mincost = min(val, mincost);
                }

                dp[i][j] = mincost;
            }
        }

        return dp[1][cuts.size() - 2];
    }
};