// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

/* 
Memoization
TC - O(n * k) + O(n)
SC - O(n * k) + O(n) extra for stack.

Without memoization, if we use plain recursion
TC would have been O(2^n) and SC would have been O(n).
*/
int helper(vector<int>& arr, int target, int index, vector<vector<int>> &dp)
{
    int mod = 1e9 + 7;

    /*
    This condition is removed to handle the cases where 0 is present in the array also.
    if(sum == 0)
        return 1;
    */
    if(index == 0)
    {
        //If array only consists of 1<= arr[i] <= n, then we don't need the below logic. We can simply return arr[0] == sum. And add another if condition outside this, which returns 1 whenver sum(target) equals 0.
        if(target == 0 && arr[index] == 0)
            return 2;       //We will get our required subset when we pick 0 and also when we don't pick 0. Therefore returning 2 to account for both of the scenarios.
        else if(target == 0 || target == arr[index])
            return 1;
        else
            return 0;
    }

    if(dp[index][target] != -1)
        return dp[index][target];

    int notpick = helper(arr, target, index - 1, dp % mod;
    int pick = 0;
    if(arr[index] <= target)
        pick = helper(arr, target - arr[index], index - 1, dp) % mod;

    return dp[index][target] = pick + notpick;
}

int findWays(vector<int> &arr, int sum)
{
    return helper(num, tar, num.size() - 1, dp);
}

/*
Tabulation
TC - O(n * k) + O(n)
SC - O(n * k)
*/

int findWays(vector<int> &arr, int sum)
{
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
        
        
    if(arr[0] <= sum)
        dp[0][arr[0]] = 1;

    //Extra base case to handle the scenario when first element of array is 0.  
    if(arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
            
    for(int i = 1; i < n; i++)
    {
        /* Important */
        //Here, j is running from 0 to sum (BOTH INCLUSIVE). This is to handle the cases where 0 is present at any index other than 0.
        /*
        Dry run this test case
        10 31
        9 7 0 3 9 8 6 5 7 6
        */
        for(int j = 0; j <= sum; j++)
        {
            int notpick = dp[i - 1][j] % mod;
            int pick = 0;
            if(arr[i] <= j)
                pick = dp[i - 1][j - arr[i]] % mod;
                    
            dp[i][j] = (pick + notpick) % mod;
        }
    }
 
    return dp[n - 1][sum];
}

/*
Space Optimization 
SC - O(K) + O(K)
*/

int findWays(vector<int> &arr, int sum)
{
    int mod = 1e9 + 7;
    vector<int> prev(k + 1, 0), curr(k + 1, 0);
        
        
    if(arr[0] <= sum)
        prev[arr[0]] = 1;

    //Extra base case to handle the scenario when first element of array is 0.  
    if(arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
            
    for(int i = 1; i < n; i++)
    {
        curr[0] = 1;
        /* Important */
        //Here, j is running from 0 to sum (BOTH INCLUSIVE). This is to handle the cases where 0 is present at any index other than 0.
        for(int j = 0; j <= sum; j++)
        {
            int notpick = prev[j] % mod;
            int pick = 0;
            if(arr[i] <= j)
                pick = prev[j - arr[i]] % mod;
                    
            curr[j] = (pick + notpick) % mod;
        }

        prev = curr;
    }
 
    return prev[sum];
}

/*
Further Space optimization - We can see that for each cell we are accessing directly above cell and one cell from it's left in current row.
Here, 'j - nums[i]' will always be a cell towards left of current cell.
So, if we start filling table from right to left, we can use single row data structure and just overwrite it's values.

SC - O(S)
*/
int findWays(vector<int> &arr, int sum)
{
    int mod = 1e9 + 7;
    vector<int> prev(k + 1, 0);
        
        
    if(arr[0] <= sum)
        prev[arr[0]] = 1;

    //Extra base case to handle the scenario when first element of array is 0.  
    if(arr[0] == 0)
        prev[0] = 2;
    else    
        prev[0] = 1;
            
    for(int i = 1; i < n; i++)
    {
        /* Important */
        //Here, j is running from 0 to sum (BOTH INCLUSIVE). This is to handle the cases where 0 is present at any index other than 0.
        for(int j = sum; j >= 0; j--)
        {
            int notpick = prev[j] % mod;
            int pick = 0;
            if(arr[i] <= j)
                pick = prev[j - arr[i]] % mod;
                    
            prev[j] = (pick + notpick) % mod;
        }
    }
 
    return prev[sum];
}