// https://leetcode.com/problems/coin-change-ii/

/*
Recursion
TC - O(2 ^ n) This will be a loose approximation. In general it will be exponential.
SC - O(target) We are not decrementing index at every step. Therefore worst case scenario depends on Target. For ex. coins [5] and target = 1. 
*/
class Solution {
public:
    int helper(vector<int>& arr, int target, int index)
    {
        if(index == 0)
        {
            if(target == 0 || target % arr[0] == 0)
                return 1;
            else
                return 0;
        }

        int pick = 0;
        if(arr[index] <= target)
            pick = helper(arr, target - arr[index], index);
            
        int notpick = helper(arr, target, index - 1);

        return pick + notpick;
    }
    int change(int amount, vector<int>& coins) 
    {
        return helper(coins, amount, coins.size() - 1);
    }
};

/*
Memoization
TC - O(n * Target)
SC - O(n * Target) + O(Target)
*/

class Solution {
public:
    int helper(vector<int>& arr, int target, int index, vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            /*
            if(target == 0 || target % arr[0] == 0)
                return 1;
            else
                return 0;
            */
            return target % arr[0] == 0;
        }

        if(dp[index][target] != -1)
            return dp[index][target];

        int pick = 0;
        if(arr[index] <= target)
            pick = helper(arr, target - arr[index], index, dp);
            
        int notpick = helper(arr, target, index - 1, dp);

        return dp[index][target] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        return helper(coins, amount, coins.size() - 1, dp);
    }
};

/* 
Tabulation
TC - O(N * Target)
SC - O(N * Target)
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, 0));

        //Initialize the first row.
        for(int j = 0; j <= amount; j++)
            if(j % coins[0] == 0)
                dp[0][j] = 1;
            //else dp[0][j] = 0 already covered in initialization.

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= amount; j++)
            {
                int notpick = dp[i - 1][j];
                int pick = 0;
                if(coins[i] <= j)
                    pick = dp[i][j - coins[i]];

                dp[i][j] = pick + notpick;
            }
        }

        return dp[n - 1][amount];
    }
};

/*
Space Optimization
SC - O(Amount)
                notpick = dp[i - 1][j]
                pick = dp[i][j - coins[i]];

We are using values to the left of cell in current row to fill the values for current cell. We can go from left to right and fill this using only 1 row.

for ex. dp[5][0] will be written first as it is not dependant on it's left cell's values. Then, use this to fill any of the cells to it's right.
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);

        //Initialize the first row.
        for(int j = 0; j <= amount; j++)
            if(j % coins[0] == 0)
                dp[j] = 1;
            //else already covered in initialization.

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j >= amount; j++)
            {
                int notpick = dp[j];
                int pick = 0;
                if(coins[i] <= j)
                    pick = dp[j - coins[i]];

                dp[j] = pick + notpick;
            }
        }

        return dp[amount];
    }
};