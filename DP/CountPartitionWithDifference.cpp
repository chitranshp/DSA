// https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1


/*
Approach - We can solve the following problem in two ways.
First Approach:
    We find dp[n - 1][0] to dp[n - 1][totalsum] where dp[i][j] represent the number of subsets from index 0 to index i having sum 'j'.

    Then we run a loop from 0 to totalsum(Both inclusive) on dp[n - 1] and sum all the values as per given condition.
        for(int s1 = 0; s1 <= totalsum; s1++)
        {
           int s2 = totalsum - s1;
           if(dp[n - 1][s1] > 0 && s1 - s2 == d)
           {
               total += dp[n - 1][s1];      //d[n - 1][s1] is the number of such subsets satisfying the given criteria,
           }
        }
    Total time complexity of this approach will be O(N) + O(N * totalsum) * O(N). We can reduce the last O(N) which we spend on iterating over last row of dp table.

Second Approach:
Given, 
    S1 - S2 = D     and a1 + a2 + ..... + an = Totalsum(S) => S1 + S2 = S
    S - S2 - S2 = D
    S - D = 2 * S2
    S2 = (S - D) / 2   All elements on RHS are constant. So we have to find all such partitions of given array where sum of partition S2 = (Totalsum - D) / 2. 
    This converts the given problem into finding a subset with given target sum.

    Edge cases:
        S - D will always be >= 0
        And array is formed by integers >= 0, therefore S2(Sum of elements in partition 2) cannot be a fraction.
        This means (S - D) needs to be an even number only then (S - D) won't be a fraction and will be an integer.

        Another edge case will be since array element can also be 0. So, we will need to add special base case to handle arr[0] == 0 and arr[i] == 0(Just start j from 0 instead of 1)
*/

/*
Approach 1
TC - O(N * totalsum) + O(N) + O(N)
SC - O(N * totalsum) can be optimized to O(N)
*/

class Solution {
  public:
    void helper(vector<int>& arr, vector<vector<int>> &dp, int target)
    {
        int mod = 1e9 + 7;
        
        /*
        for(int i = 0; i < arr.size(); i++)
            dp[i][0] = 1;
        */
            
        if(arr[0] <= target)        //If arr[0] == 0, then this will be overwritten in next step.
            dp[0][arr[0]] = 1;
            
        if(arr[0] == 0)
            dp[0][0] = 2;
        // Covered in first for loop initialization
        else
            dp[0][0] = 1;
            
        for(int i = 1; i < arr.size(); i++)
        {
            for(int j = 0; j <= target; j++)
            {
                int notpick = dp[i - 1][j];
                int pick = 0;
                if(arr[i] <= j)
                    pick = dp[i - 1][j - arr[i]];
                    
                dp[i][j] = (pick + notpick) % mod;
            }
        }
        
    }
    int countPartitions(int n, int d, vector<int>& arr) 
    {
        int totalsum = 0;
        totalsum = accumulate(arr.begin(), arr.end(), totalsum);
        vector<vector<int>> dp(n, vector<int> (totalsum + 1, 0));
        
        helper(arr, dp, totalsum);
        
        int total = 0;
        for(int j = 0; j <= totalsum; j++)
        {
           int s2 = totalsum - j;
           if(dp[n - 1][j] > 0 && j - s2 == d)
           {
               total += dp[n - 1][j];
           }
        }
        
        return total;
    }   
};

/* 
Approach 2 - Memoization
TC - O(N * totalsum) + O(N)
SC - O(N * totalsum) + O(N)
*/

class Solution {
  public:
    int helper(vector<int>& arr, vector<vector<int>> &dp, int target, int index)
    {
        int mod = 1e9 + 7;
            
        if(index == 0)
        {
            if(target == 0 && arr[0] == 0)
                return 2;
            else if(target == 0 || arr[index] == target)
                return 1;
            else
                return 0;
        }
            
        if(dp[index][target] != -1)
            return dp[index][target];
            
        int notpick = helper(arr, dp, target, index - 1);
        int pick = 0;
        if(arr[index] <= target)
            pick = helper(arr, dp, target - arr[index], index - 1);
            
        return dp[index][target] = (pick + notpick) % mod;
        
    }
    int countPartitions(int n, int d, vector<int>& arr) 
    {
        int totalsum = 0;
        totalsum = accumulate(arr.begin(), arr.end(), totalsum);
        vector<vector<int>> dp(n, vector<int> (totalsum + 1, -1));
        
        if(totalsum - d < 0 || (totalsum - d) % 2 == 1)
            return 0;
        
        int s2 = (totalsum - d) / 2;
        return helper(arr, dp, s2, n - 1);
    }   
};

/*
Tabulation
TC - O(N * totalsum) + O(N)
SC - O(N * totalsum)
*/


class Solution {
  public:
    int helper(vector<int>& arr, vector<vector<int>> &dp, int target)
    {
        int mod = 1e9 + 7;
            
        if(arr[0] <= target)        //If arr[0] == 0, then this will be overwritten in next step.
            dp[0][arr[0]] = 1;
            
        if(arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
            
        for(int i = 1; i < arr.size(); i++)
        {
            //This loop is starting from 0 to account for 0 in array.
            for(int j = 0; j <= target; j++)
            {
                int notpick = dp[i - 1][j];
                int pick = 0;
                if(arr[i] <= j)
                    pick = dp[i - 1][j - arr[i]];
                    
                dp[i][j] = (pick + notpick) % mod;
            }
        }
        
        return dp[arr.size() - 1][target];        
    }
    
    int countPartitions(int n, int d, vector<int>& arr) 
    {
        int totalsum = 0;
        totalsum = accumulate(arr.begin(), arr.end(), totalsum);
        vector<vector<int>> dp(n, vector<int> (totalsum + 1, 0));
        
        if(totalsum - d < 0 || (totalsum - d) % 2 == 1)
            return 0;
        
        int s2 = (totalsum - d) / 2;
        
        return helper(arr, dp, s2);
        
    }   
};

/*
Space Optimization
SC - O(N) + O(N)
*/


class Solution {
  public:
    int helper(vector<int>& arr, int target)
    {
        int mod = 1e9 + 7;
        vector<int> prev(totalsum + 1, 0);
            
        if(arr[0] <= target)        //If arr[0] == 0, then this will be overwritten in next step.
            prev[arr[0]] = 1;
            
        if(arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;
            
        for(int i = 1; i < arr.size(); i++)
        {
            vector<int> curr(target + 1, 0);

            //This loop is starting from 0 to account for 0 in array.
            for(int j = 0; j <= target; j++)
            {
                int notpick = prev[j];
                int pick = 0;
                if(arr[i] <= j)
                    pick = prev[j - arr[i]];
                    
                curr[j] = (pick + notpick) % mod;
            }

            prev = curr;
        }
        
        return prev[target];        
    }
    
    int countPartitions(int n, int d, vector<int>& arr) 
    {
        int totalsum = 0;
        totalsum = accumulate(arr.begin(), arr.end(), totalsum);
        
        if(totalsum - d < 0 || (totalsum - d) % 2 == 1)
            return 0;
        
        int s2 = (totalsum - d) / 2;
        
        return helper(arr, s2);      
    }   
};