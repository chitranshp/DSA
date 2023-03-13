// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

/*
Recursion
TC - Exponential
SC - O(W)
*/
// User function Template for C++

class Solution{
public:
    int helper(int W, int val[], int wt[], int index)
    {
        if(W == 0)
            return 0;
            
        if(index < 0)
            return 0;
            
        if(index == 0)
        {
            /*
            Redundant as below cases will be handled by the final return statement anyhow.
            if(W == 0 || W < wt[0])
                return 0;
            if(W >= wt[0])
            */
            return val[index] * (W - (W % wt[0]));
        }
        
        int notpick = 0 + helper(W, val, wt, index - 1);
        int pick = INT_MIN;
        if(wt[index] <= W)
            pick = val[index] + helper(W - wt[index], val, wt, index); //As each item can be pick any number of times, therefore not decrementing index. So that in next call, it will again check whether same item can again be included or not.
            
        return max(pick, notpick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return helper(W, val, wt, N - 1);
    }
};

/*
Memoization
TC - O(N * W)
SC - O(N * W) + O(W) (For Stack)
*/
class Solution{
public:
    int helper(int W, int val[], int wt[], int index, vector<vector<int>> &dp)
    {
        if(W == 0 || W < 0)
            return 0;
            
        if(index == 0)
        {
            /*
            //Not needed as for these cases, below condition will anyhow return 0.
            if(W == 0 || W < wt[0])
                return 0;
            */
            //if(W >= wt[0])
            return val[0] * (W / wt[0]);
        }      
        
        if(dp[index][W] != -1)
            return dp[index][W];
        
        int notpick = 0 + helper(W, val, wt, index - 1, dp);
        int pick = ;INT_MIN;
        if(wt[index] <= W)
            pick = val[index] + helper(W - wt[index], val, wt, index, dp);
            
        return dp[index][W] = max(pick, notpick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int> (W + 1,  -1));
        return helper(W, val, wt, N - 1, dp);
    }
};

/*
Tabulation
TC - O(N * W)
SC - O(N * W)
*/

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int> (W + 1,  0));
        
        //For j < wt[0], value of dp cells will be 0, which is already set during initialization.
        for(int j = wt[0]; j <= W; j++)
            dp[0][j] = val[0] * (j / wt[0]);
            
        for(int i = 1; i < N; i++)
        {
            //Values for 0th column was not set as part of base case.
            for(int j = 0; j <= W; j++)
            {
                int notpick = 0 + dp[i - 1][j];
                int pick = INT_MIN;
                if(wt[i] <= j)
                    pick = val[i] + dp[i][j - wt[i]];
                    
                dp[i][j] = max(pick, notpick);
            }
        }
            
        return dp[N - 1][W];
    }
};

/*
SpaceOptimization
SC - O(W)
*/

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        //vector<vector<int>> dp(N, vector<int> (W + 1,  0));
        vector<int> dp(W + 1, 0);
        
        //For j < wt[0], value of dp cells will be 0, which is already set during initialization.
        for(int j = wt[0]; j <= W; j++)
            dp[j] = val[0] * (j / wt[0]);
            
        for(int i = 1; i < N; i++)
        {
            //Values for 0th column was not set as part of base case.
            for(int j = 0; j <= W; j++)
            {
                //First time dp[j] being used for this row, so would be containing old values of previous row.
                //After using it for calculating new cell value, we will overwrite it with new value for current row.
                int notpick = 0 + dp[j];
                int pick = INT_MIN;
                
                //dp[j - wt[i]] would have been already overwritten by new value for current row by this time.
                if(wt[i] <= j)
                    pick = val[i] + dp[j - wt[i]];
                    
                dp[j] = max(pick, notpick);
            }
        }
            
        return dp[W];
    }
};