// https://leetcode.com/problems/coin-change/
// Coin change - Infinite supply

/*
Recursion
TC - Exponential (>= O(2 ^ n))
SC - O(Target) As instead of index decrementing by 1, in case pick target will decrease by 1 and our recursion calls will depend on that.
*/

int findmincoin(vector<int> &coins, int target, int index)
{
    if(index == 0)
    {
        //If target = 6 and coins[0] = 10, 6 % 10 will be 6. Therefore, it will go in else and return 1e8
        //Make sure to check all coins are greater then 0 to prevent divide by 0.
        if(target % coins[0] == 0)       //Modulo will only be 0 when remaining target can be completely achieved by coins of coins[0] denomination only. And if this can be achieved in next step we will find the required number of coins used for this and return it.
            return target / coins[0];    //This will return the number of coins of type coins[0] required to fullfill target amount.
        else
            return 1e8;
    }

    /*
    if(target == 0)
        return 0;
    else if(target < 0)
        return 1e8;
    */

    int notpick = 0 + findmincoin(coins, target, index - 1);
    int pick = 1e8;
    if(coins[index] <= target)
        pick = coins[index] + findmincoin(coins, target - coins[index], index); //Here, we are not decrementing the index, as there is another option that same coin can be included multiple times to get the required number of coins. By calling the function without decrementing the index, we will check whether we can take another coin of same denomination and if yes what will be the total number of coins used.

    return min(pick, notpick);
}

int coinChange(vector<int>& coins, int amount) 
{
    int res = helper(coins, amount, coins.size() - 1);
    if(res >= 1e8)
        return -1;

    return res;
}

/*
Memoization
TC - O(n * Target)
SC - O(n * Target) + O(Target)
*/

class Solution {
public:
    int helper(vector<int>& coins, int target, int index, vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            if(target % coins[0] == 0)
                return target / coins[0];
            else
                return 1e8;
        }

        /*
        if(target == 0)
            return 0;
        else if(target < 0)
            return 1e8;
        */

        if(dp[index][target] != -1)
            return dp[index][target];

        int notpick = 0 + helper(coins, target, index - 1, dp);
        int pick = 1e8;
        if(coins[index] <= target)
            pick = 1 + helper(coins, target - coins[index], index, dp);

        return dp[index][target] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        int ans = helper(coins, amount, coins.size() - 1, dp);

        if(ans >= 1e8)
            return -1;

        return ans;
    }
};

/*
Tabulation
TC - O(N * Target)
SC - O(N * Target)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        
        for(int j = 0; j <= amount; j++)
        {
            if(j % coins[0] == 0)
                dp[0][j] = j / coins[0];
            else
                dp[0][j] = 1e8;
        }

        for(int i = 1; i < n; i++)
        {
            //From 0 till amount
            for(int j = 0; j <= amount; j++)
            {
                int notpick = 0 + dp[i - 1][j];
                int pick = 1e8;
                if(coins[i] <= j)
                    pick = 1 + dp[i][j - coins[i]];     //dp[i] as we are not decrementing index

                dp[i][j] = min(pick, notpick);
            }
        }
        return dp[n - 1][amount] >= 1e8? -1 : dp[n - 1][amount];
    }
};

/*
Space Optimization - We are using 2 rows dp[i][j - coins[i]] and dp[i - 1][j]. So, we can use two arrays instead of the whole table.
TC - O(N * Target)
SC - O(Target) + O(Target)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        
        for(int j = 0; j <= amount; j++)
        {
            if(j % coins[0] == 0)
                prev[j] = j / coins[0];
            else
                prev[j] = 1e8;
        }

        for(int i = 1; i < n; i++)
        {
            //From 0 till amount. Left to right. As we need the values for values of columns less than index j to fill for curr[j] (curr[j - coins[i]])
            for(int j = 0; j <= amount; j++)
            {
                int notpick = 0 + prev[j];
                int pick = 1e8;
                if(coins[i] <= j)
                    pick = 1 + curr[j - coins[i]];     //curr[i] as we are not decrementing index

                curr[j] = min(pick, notpick);
            }

            prev = curr;
        }
        return prev[amount] >= 1e8? -1 : prev[amount];
    }
};

/*
Further Space Optimization - We notice that for previous row, we need the value of cell directly above and rest of the cells to the left of that are not needed in previous row(If we are calculating L to R) and can be discarded.
So, we can use the same row and overwrite the values to the left with new values of the current row.

    up = dp[i - 1][j]
    left = dp[i][j - coins[i]]

Therefore instead of 2 vectors we can use only 1 to store values for both previous and current row.
TC - O(N * Target)
SC - O(Target)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> prev(amount + 1, 0);
        
        for(int j = 0; j < amount + 1; j++)
        {
            if(j % coins[0] == 0)
                prev[j] = j / coins[0];
            else
                prev[j] = 1e8;
        }

        for(int i = 1; i < coins.size(); i++)
        {
            for(int j = 0; j <= amount; j++)
            {
                int notpick = 0 + prev[j];
                int pick = 1e8;
                if(coins[i] <= j)
                    pick = 1 + prev[j - coins[i]];

                prev[j] = min(pick, notpick);
            }

            
        }
        return prev[amount] >= 1e8? -1 : prev[amount];
    }
};