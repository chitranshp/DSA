// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

/*
Recursion + Memoization
We are given a transaction cap of k which means 
            B   S   B   S
            0   1   2   3
        cap 4   3   2   1   0
We can code it in such a way that transactioncap = 2 * 2(2 - represents buy and sell which make up one transaction)
And we can ignore the canBuy variable. Instead of that we can use this modified transactionCap to tell whether we can perform buy or sell.
If transactionCap is even we can perform a buy, if it is odd we can perform a sell. If it is < 0 or > 3, that means we have exhausted available transactions.
TC - O(n * 4)
SC - O(n * (2 * k)) + O(n) as we can perform k buy operations and k sell operations .

Alternative approach - We can keep transaction as k and use a 3-D vector instead of form dp[prices.size][canBuy][k]
And can optimize it to 2-D space complexity which will be same as approach 1 (O(2 * k))

class Solution {
public:
    int helper(vector<int> &prices, int i, int buy, int cap, vector<vector<vector<int>>> &dp)
    {
        if(i == prices.size() || cap == 0)
            return 0;

        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;

        if(buy)
            profit = max(-prices[i] + helper(prices, i + 1, 0, cap, dp), 0 + helper(prices, i + 1, 1, cap, dp));
        else
            profit = max(prices[i] + helper(prices, i + 1, 1, cap - 1, dp), 0 + helper(prices, i + 1, 0, cap, dp));

        return profit;
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        int canBuy = 1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k + 1, -1)));
        return helper(prices, 0, canBuy, k, dp);
    }
};
*/

class Solution {
public:
    int helper(vector<int> &prices, int i, int cap, vector<vector<int>> &dp)
    {
        if(i == prices.size() || cap == 0)
            return 0;

        if(dp[i][cap] != -1)
            return dp[i][cap];

        int profit = 0;

        if(cap % 2 == 0)
            profit = max(-prices[i] + helper(prices, i + 1, cap - 1, dp), 0 + helper(prices, i + 1, cap, dp));
        else
            profit = max(prices[i] + helper(prices, i + 1, cap - 1, dp), 0 + helper(prices, i + 1, cap, dp));

        return dp[i][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        int canBuy = 1;
        vector<vector<int>> dp(n, vector<int> (2 * k + 1, -1));
        return helper(prices,0, 2 * k, dp);
    }
};

/*
Tabulation
We are skipping base cases here as they are already covered as part of initialization.
TC - O(n * (2 * k))
SC - O(n * (2 * k))
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2 * k + 1, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int cap = 1; cap <= 2 * k; cap++)
            {
                int profit = 0;

                if(cap % 2 == 0)
                    profit = max(-prices[i] + dp[i + 1][cap - 1], 0 + dp[i + 1][cap]);  //If i = n - 1, then i + 1 will be equal to n. Therefore, size of dp must be [n][2 * k + 1]
                else
                    profit = max(prices[i] + dp[i + 1][cap - 1], 0 + dp[i + 1][cap]);

                dp[i][cap] = profit;
            }
        }

        return dp[0][2 * k];
    }
};

/*
SpaceOptimization
TC - O(n * (2 * k))
SC - O(2 * K)
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> dp(2 * k + 1, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            for(int cap = 2 * k; cap >= 1; cap--)
            {
                int profit = 0;

                if(cap % 2 == 0)
                    profit = max(-prices[i] + dp[cap - 1], 0 + dp[cap]);  //If i = n - 1, then i + 1 will be equal to n. Therefore, size of dp must be [n][2 * k + 1]
                else
                    profit = max(prices[i] + dp[cap - 1], 0 + dp[cap]);

                dp[cap] = profit;
            }
        }

        return dp[2 * k];
    }
};

