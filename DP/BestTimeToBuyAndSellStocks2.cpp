// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*
Recursion - At each index, we can only buy if we are not holding previously bought stock. And if we can sell only if we are holding prevously bought stock.
And even in those 2 cases, we will have a choice, we can buy/sell or we can choose to hold our position in hopes of getting better price in future.

If we are buying we will just subtract profit by that price and if we are selling, we will add that price to our profit.
TC - O(2 * m)
SC - O(m)
*/

class Solution {
public:
    int helper(vector<int> &prices, int canbuy, int index)
    {
        if(index == prices.size())
            return 0;

        int profit = 0;
        if(canbuy)
        {
            //We have two options, we can choose to buy or we can choose to with hold our money if we deem that prices are too high and might come down in near future.
            //If we are buying up stock here, only then we can sell for next stock
            profit = max(-prices[index] + helper(prices, 0, index + 1), 0 + helper(prices, 1, index + 1));
        }
        else
            //If we are selling up our stock here, only then we can buy for next stock
            //We have two options, we can choose to sell or we can choose to with hold our stock if we deem that prices are too low and might come go up in near future.
            profit = max(prices[index] + helper(prices, 1, index + 1), 0 + helper(prices, 0, index + 1));

        return profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int canbuy = 1; //At first index, we are free to buy.
        return helper(prices, canbuy, 0);
    }
};

/*
Memoization
TC - O(m * 2)
SC - O(m * 2) + O(m)
*/

class Solution {
public:
    int helper(vector<int> &prices, int canbuy, int index, vector<vector<int>> &dp)
    {
        if(index == prices.size())
            return 0;

        if(dp[index][canbuy] != -1)
            return dp[index][canbuy];

        int profit = 0;
        if(canbuy)
        {
            profit = max(-prices[index] + helper(prices, 0, index + 1, dp), 0 + helper(prices, 1, index + 1, dp));
        }
        else
            profit = max(prices[index] + helper(prices, 1, index + 1, dp), 0 + helper(prices, 0, index + 1, dp));

        return dp[index][canbuy] = profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int canbuy = 1;
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return helper(prices, canbuy, 0, dp);
    }
};

/*
Tabulation
TC - O(m * 2)
SC - O(m * 2)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int canBuy = 1;
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));

        //Base Case
        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int index = n - 1; index >= 0; index--)
        {
            for(int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;

                if(canBuy)
                    profit = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
                else
                    profit = max(prices[index] + dp[index + 1][1], 0 + dp[index + 1][0]);

                dp[index][canBuy] = profit;
            }
        }

        //For first index, we have the liberty to buy or not. Therefore, canbuy will be 1 and that case covers both buying and notbuying.
        return dp[0][1];
    }
};

/*
SpaceOptimization - We are only using i + 1 th row's values to fill for ith row. So, we can just use one dp[2] and keep overwriting older values with new one's.
TC - O(m * 2)
SC - O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int canBuy = 1;
        int n = prices.size();
        vector<int> dp(2, -1);

        dp[0] = 0;
        dp[1] = 0;

        for(int index = n - 1; index >= 0; index--)
        {
            for(int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;

                if(canBuy)
                    profit = max(-prices[index] + dp[0], 0 + dp[1]);
                else
                    profit = max(prices[index] + dp[1], 0 + dp[0]);

                dp[canBuy] = profit;
            }
        }

        //For first index, we have the liberty to buy or not. Therefore, canbuy will be 1 and that case covers both buying and notbuying.
        return dp[1];
    }
};

/*
Alternative approach(Greedy) - We want to buy at a day where price is lower and sell when price is higher. If we plot the prices in form of graph, we basically want to buy at a valley(point surrounded by higher prices on both sides) and sell it at a peak.
So, we can write a for loop which will stop at a valley and find the next corresponding highest peak untill price again start falling and then sell it. 
After that point we again start looking for next valley and peak untill array is exhausted.
TC - O(m)
SC - O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
       int buy = 0, sell = 0, days = prices.size(), profit = 0;
       while(buy < days && sell < days)
       {
           while(buy < days - 1 && prices[buy + 1] < prices[buy])
            buy++;
           
           //When the previous loop terminates, it's gurranted that either buy = sell = days - 1 or prices[buy + 1] will be >= prices[buy]. So, next loop will run atleast 1 time if sell != days - 1 and we will reach a peak or reach end of the array.
           sell = buy;

           //We are compairing price for sell + 1 and sell. That's why sell is bounded by days - 1. To prevent it going out of bounds. Same is the case for previous inner while loop.
           while(sell < days - 1 && prices[sell + 1] > prices[sell])
            sell++;

            //If buy == sell == n - 1 then prices[sell] - prices[buy] will be 0.
           profit = profit + prices[sell] - prices[buy];
           
           //Update for next iteration. We can again start looking for next valley(day to buy stock) only after the current sell date.
           buy = sell + 1; 
       }

       return profit;
    }
};