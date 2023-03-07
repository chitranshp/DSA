// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

/*
Recursion
TC - O(2 ^ N)
SC - O(N)
*/

class Solution
{
    public:
    int helper(int target, int wt[], int val[], int index)
    {
        if(target == 0)
            return 0;
            
        if(index == 0)
        {
            if(wt[0] <= target)
                return val[0];       //Pick
            else
                return 0;           //NotPick
        }
        
        int notpick = 0 + helper(target, wt, val, index - 1);
        int pick = 0; 
        if(wt[index] <= target)
            pick = val[index] + helper(target - wt[index], wt, val, index - 1);
            
        return max(pick, notpick);
    }

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return helper(W, wt, val, n - 1);
    }
};

/* 
dp[i][w] represents the max value(profit) that can be generated from index 0 to i, with maximum capacity of bag being w
Memoization. For index 0, dp[0][x] all will be 0 from x = 0 to x < wt[0] as the only item that is available to be placed in the bag in more than the max. capacity of bag.
And after x = wt[0] to x = W (Overall max. capacity of knapsack), all values will be equal to val[0] as no matter what the capacity of bag is at index = 0, only 1 item is available ie wt[0].
TC - O(N * W)
SC - O(N * W) + O(N)
*/
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int wt[], int val[], int target, int index, vector<vector<int>> &dp)
    {
        if(target == 0)
            return 0;
        // For last item, we will take the decision to pick or not pick based on the weight of that item and the remaining capacity of the bag.
        if(index == 0)  //If we are at last item
        {
            //And if we still have space left in that bag such that last item can fit
            if(wt[0] <= target)     //(Pick)
                return val[0];      //Return the value of last item or include the last item
            else                    //(Notpick) Dont include the last item, whatever value we have till now is the final value.
                return 0;
        }
        
        if(dp[index][target] != -1)
            return dp[index][target];
        
        int notpick = 0 + (wt, val, target, index - 1, dp);
        int pick = 0;
        if(wt[index] <= target)
            pick = val[index] + helper(wt, val, target - wt[index], index - 1, dp);
            
        return dp[index][target] = max(pick, notpick);
    }

    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int> (W + 1, -1));
       return helper(wt, val, W, n - 1, dp);
    }
};

/*
Tabulation
TC - O(N * W)
SC - O(N * W)
*/
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int> (W + 1, 0));   //If(target == 0) return 0 this is covered by this.
       
       /*
       if(index === 0) 
        if(wt[0] <= target) 
          return val[0]. This is covered here.
      */
       for(int i = wt[0]; i <= W; i++)
        dp[0][i] = val[0];
       
       /* First row and first column are handled by both of these previous base conditions */
       for(int i = 1; i < n; i++)
       {
           for(int target = 1; target <= W; target++)
           {
               int notpick = 0 + dp[i - 1][target];
               int pick = 0; 
               if(wt[i] <= target)
                pick = val[i] + dp[i - 1][target - wt[i]];
                
               dp[i][target] = max(pick, notpick);
           }
       }
       return dp[n - 1][W];
    }
};

/*
SpaceOptimization
TC - O(N * W)
SC - O(W) + O(W)
*/

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       //vector<vector<int>> dp(n, vector<int> (W + 1, 0));   //If(target == 0) return 0 this is covered by this.
       vector<int> prev(W + 1, 0);
       
       //if(index === 0) if(wt[0] <= target) return val[0]. This is covered here.
       for(int i = wt[0]; i <= W; i++)
        prev[i] = val[0];
       
       for(int i = 1; i < n; i++)
       {
           vector<int> curr(W + 1, 0);
           for(int target = 1; target <= W; target++)
           {
               int notpick = 0 + prev[target];
               int pick = 0; 
               if(wt[i] <= target)
                pick = val[i] + prev[target - wt[i]];
                
               curr[target] = max(pick, notpick);
           }
           
           prev = curr;
       }
       return prev[W];
    }
};

/*
Further Space optimization - We can see that although we are using two rows of dp table at a time. We can reuse the same one row to store the second row also.
We need the values directly above the current location and value of dp[i - 1][target - wt[i]]. 
'target - wt[i]' will always be in left of current location. All values to right of the current location are not needed for calculation of values for same row.
Therefore, if we start filling current row from right to left. We can store both past and current values in same row.
TC - O(N * W)
SC - O(W)
*/

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       //vector<vector<int>> dp(n, vector<int> (W + 1, 0));   //If(target == 0) return 0 this is covered by this.
       vector<int> dp(W + 1, 0);
       
       //if(index === 0) if(wt[0] <= target) return val[0]. This is covered here.
       for(int i = wt[0]; i <= W; i++)
        dp[i] = val[0];
       
       for(int i = 1; i < n; i++)
       {
           for(int target = W; target >= 1; target--)
           {
               int notpick = 0 + dp[target];
               int pick = 0; 
               if(wt[i] <= target)
                pick = val[i] + dp[target - wt[i]];
                
               dp[target] = max(pick, notpick);
           }
       }
       return dp[W];
    }
};