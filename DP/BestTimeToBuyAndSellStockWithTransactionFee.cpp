// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

/*
Recursion - We will add the transaction fee whenever we are completing our transaction i.e. making a sell operation.
TC - Exponential
SC - O(n)
*/

class Solution {
public:
    int helper(vector<int> &prices, int i, int buy, int fee)
    {
        if(i == prices.size())
            return 0;

        int profit = 0;
        if(buy == 1)
        {
            profit = max(-prices[i] + helper(prices, i + 1, 0, fee), 0 + helper(prices, i + 1, 1, fee));
        }
        else if(buy == 0)
        {
            profit = max(-fee + prices[i] + helper(prices, i + 1, 1, fee), 0 + helper(prices, i + 1, 0, fee));
        }

        return profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) 
    {
        return helper(prices, 0, 1, fee);   
    }
};

/*
Memoization
TC - O(n * 2)
SC - O(n * 2) + O(n)
*/

class Solution {
public:
    int helper(vector<int> &prices, int i, int buy, vector<vector<int>> &dp, int fee)
    {
        if(i == prices.size())
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;
        if(buy == 1)
        {
            profit = max(-prices[i] + helper(prices, i + 1, 0, dp, fee), 0 + helper(prices, i + 1, 1, dp, fee));
        }
        else if(buy == 0)
        {
            profit = max(-fee + prices[i] + helper(prices, i + 1, 1, dp, fee), 0 + helper(prices, i + 1, 0, dp, fee));
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) 
    {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return helper(prices, 0, 1, dp, fee);   
    }
};

/*
Tabulation
TC - O(n * 2)
SC - O(n * 2)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<vector<int>> dp(prices.size() + 1, vector<int> (2, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if(buy == 1)
                {
                    profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                }
                else if(buy == 0)
                {
                    profit = max(-fee + prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                }

                dp[i][buy] = profit;
            }
        }
        return dp[0][1];   
    }
};

/*
Space Optimization
TC - O(n * 2)
SC - Two vectors of size 2 which is almost as good as O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if(buy == 1)
                {
                    profit = max(-prices[i] + ahead[0], 0 + ahead[1]);
                }
                else if(buy == 0)
                {
                    profit = max(-fee + prices[i] + ahead[1], 0 + ahead[0]);
                }

                curr[buy] = profit;
            }

            ahead = curr;
        }
        return ahead[1];   
    }
};

/*
Further Optimization - Remove the inner loop
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            curr[1] = max(-prices[i] + ahead[0], 0 + ahead[1]);
            curr[0] = max(-fee + prices[i] + ahead[1], 0 + ahead[0]);

            ahead = curr;
        }
        return curr[1];   
    }
};

