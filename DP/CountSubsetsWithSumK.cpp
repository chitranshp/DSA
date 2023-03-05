#include <bits/stdc++.h> 
int helper(vector<int>& arr, int target, int index, vector<vector<int>> &dp)
{
    if(index == 0)
    {
        if(target == 0 && arr[index] == 0)
            return 2;       //We will get our required subset when we pick 0 and also when we don't pick 0. Therefore returning 2 to account for both of the scenarios.
        if(target == 0 || target == arr[index])
            return 1;

        return 0;
    }

    if(dp[index][target] != -1)
        return dp[index][target];

    int notpick = helper(arr, target, index - 1, dp);
    int pick = 0;
    if(arr[index] <= target)
        pick = helper(arr, target - arr[index], index - 1, dp);

    return dp[index][target] = pick + notpick;
}
int findWays(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(arr.size(), vector<int> (sum + 1, 0));
    for(int i = 0; i < n; i++)
        {
            if(arr[0] == 0)
                dp[i][0] = 2;
            else
                dp[i][0] = 1;
        }
        
        if(arr[0] <= sum && arr[0] != 0)
            dp[0][arr[0]] = 1;
            
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                int notpick = dp[i - 1][j];
                int pick = 0;
                if(arr[i] <= j)
                    pick = dp[i - 1][j - arr[i]];
                    
                dp[i][j] = pick + notpick;
            }
        }

        return dp[n - 1][sum];
    //return helper(num, tar, num.size() - 1, dp);
}