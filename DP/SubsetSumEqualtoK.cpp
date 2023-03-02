// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?

#include <bits/stdc++.h> 
/*
f(j, target) -> This signifies whether from index 0 to j, whether we can get a subset whose sum is equal to target.
At every step, we have 2 choices
TC = O(2 ^ N)
SC = O(N)

With Memoization
TC - O(N * k)
Sc - O(N * k) + O(N)
*/
bool helper(int target, vector<int>& arr, int index, vector<vector<int>> &dp)
{
    if(target == 0)
        return true;

    if(index == 0)
        return arr[0] == target;

    if(dp[index][target] != -1)
        return dp[index][target];

    bool notpick = helper(target, arr, index - 1, dp);
    bool pick = false;
    if(target >= arr[index])
        pick = helper(target - arr[index], arr, index - 1, dp);

    return dp[index][target] = pick || notpick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<int>> dp(1001, vector<int> (1001, -1));
    return helper(k, arr, n - 1, dp);
}


/* 
Tabulation
TC - O(N * k)
Sc - O(N * k)
*/
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<bool>> dp(n, vector<bool> (k + 1, false));

    for(int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++)
    {
        for(int target = 1; target <= k; target++)
        {
            bool notpick = dp[i - 1][target];
            bool pick = false;
            if(arr[i] <= target)
                pick = dp[i - 1][target - arr[i]];

            dp[i][target] = pick || notpick;
        }
    }

    return dp[n - 1][k];
}

/* ToDo Space optimal approach */
