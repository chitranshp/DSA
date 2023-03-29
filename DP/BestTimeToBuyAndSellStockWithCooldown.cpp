// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

/*
Recursion - We can continue with same approach as previous problems of Buy and sell stock. The only difference here is, we need to track when we are in cooldown and skip stock for that day.
To keep track of cooldown, we can use another variable 'inCooldown' or we can use the same 'buy' variable for this. We can use buy == 3 to tell we are in cooldown and we should move to next day.

When we will be in cooldown?
We will be in cooldown, when we have completed a transaction on previous day which mean we have sold the stocks on the day prior(To be able to sold stock, we must also have bought it prevously)
So, whenever, we are selling a stock ie. completing a transaction we will set buy value as 2. 
And on next day, we will set it value as 1 again meaning we can buy again on the day next to it.

Approach2: Instead of using buy == 2 for tracking cooldown and then not buying and moving to next day on the cooldown day.
We can do is after doing a sell operation, we can directly go to the day + 2 instead of day + 1, as anyhow we will be on cooldown on that day won't be doing either a buy or sell operation resulting in change in profit on that day.
Our condition with this approach will be
        if(buy == 1)
            profit = max(-prices[i] + helper(prices, i + 1, 0), 0 + helper(prices, i + 1, 1));
        else if(buy == 0)
            profit = max(prices[i] + helper(prices, i + 2, 1), 0 + helper(prices, i + 1, 0));

Rest of the code will remain same.

TC - Exponential
SC - O(n) for recursion stack.
*/

class Solution {
public:
    int helper(vector<int> &prices, int i, int buy)
    {
        if(i >= prices.size())
            return 0;

        int profit = 0;

        if(buy == 1)
            profit = max(-prices[i] + helper(prices, i + 1, 0), 0 + helper(prices, i + 1, 1));
        else if(buy == 0)
            profit = max(prices[i] + helper(prices, i + 1, 2), 0 + helper(prices, i + 1, 0));
            //profit = max(prices[i] + helper(prices, i + 2, 1), 0 + helper(prices, i + 1, 0));
        else if(buy == 2)   //Cannot buy, in cooldown.
            profit = 0 + helper(prices, i + 1, 1);

        return profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        return helper(prices, 0, 1);   
    }
};

/*
Memoization
TC - O(n * 3)
SC - O(n * 3) + O(n)
*/

class Solution {
public:
    int helper(vector<int> &prices, int i, int buy, vector<vector<int>> &dp)
    {
        if(i == prices.size())
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if(buy == 1)
            profit = max(-prices[i] + helper(prices, i + 1, 0, dp), 0 + helper(prices, i + 1, 1, dp));
        else if(buy == 0)
            profit = max(prices[i] + helper(prices, i + 1, 2, dp), 0 + helper(prices, i + 1, 0, dp));
        else if(buy == 2)
            profit = 0 + helper(prices, i + 1, 1, dp);

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        vector<vector<int>> dp(prices.size(), vector<int> (3, -1));
        return helper(prices, 0, 1, dp);   
    }
};

/*
Tabulation
TC - O(n * 3)
SC - O(n * 3)

If we follow the second approach, our complexities will be
TC - O(n * 2)
SC - O(n * 2)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        //For approach 2, it will be of size prices.size() + 2, as we are accessing dp[i + 2] when i == n - 1.
        vector<vector<int>> dp(prices.size() + 1, vector<int> (3, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            //If we are following approach 2, make sure to keep it as buy <= 1
            for(int buy = 0; buy <= 2; buy++)
            {
                int profit = 0;
                /*
                Base case
                dp[i + 1] row is already having value as all zeroes as part of initializatin
                */
                if(buy == 1)
                    profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                else if(buy == 0)
                    profit = max(prices[i] + dp[i + 1][2], 0 + dp[i + 1][0]);
                else if(buy == 2)
                    profit = 0 + dp[i + 1][1];

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];   
    }
};

/*
Space optimization for approach1
TC - O(n * 3)
SC - O(1) as only 2 vectors each of constant size.

Another thing we can do is remove the inner loop, which we are using to iterate over buy. 
Instead of that we can just keep it like this. This way we can compute for whole row in loop itself.
                for(int i = n - 1; i >= 0; i--)
                {
                    //This line will only execute when buy == 1
                    dp[i][0] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                    //This line will only execute when buy == 0
                    dp[i][1] = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
                }

TC - O(n)
SC - O(n * 2)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> ahead(3, 0), curr(3, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            for(int buy = 0; buy <= 2; buy++)
            {
                int profit = 0;

                if(buy == 1)
                    profit = max(-prices[i] + ahead[0], 0 + ahead[1]);
                else if(buy == 0)
                    profit = max(prices[i] + ahead[2], 0 + ahead[0]);
                else if(buy == 2)
                    profit = 0 + ahead[1];

                curr[buy] = profit;
            }

            ahead = curr;
        }

        return ahead[1];   
    }
};

/*
Space Optimization for  - Here we are dependant on 2 front rows dp[i + 1] dp[i + 2]. So, we will change our method.
First we will remove the inner loop and then we will be using two front vectors and one curr vector.

TC - O(n)
SC - O(3) which is as good as O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> front2(2, 0), front1(2, 0), curr(2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            curr[1] = max(-prices[i] + front1[0], 0 + front1[1]);
            curr[0] = max(prices[i] + front2[1], 0 + front1[0]);

            front2 = front1;
            front1 = curr;
        }

        return curr[1];   
    }
};