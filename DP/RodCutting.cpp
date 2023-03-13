/* 
Recursion
TC - Exponential
SC - O(Target or RodLength)
*/

class Solution{
  public:
  
    /*
    We can think of this problem as we have to find all such rod length combinations that all those combinations sum up to 'n'. And for all
    those combinations we have to find the combination which gives the maximum price.
    
    One more thing for  a rod of length 5. We can break it into 5 pieces each of size 1. This shows that there is infinite supply of rods and problem is kind of unbounded.
    
    Why it is 2d dp and not 1-D dp?
    Becaues our helper function has 2 parameters which are changing for each call, they are index and n. So, to track max possible prices across combination of these two variables, we will be using 2D dp.
    
    dp[ind][len] represents till index 'ind', the maximum possible price we can get for a rod having length 'len'.
    */
    int helper(int price[], int index, int RemainingRodLength)
    {
        if(index == 0)
        {
            if(RemainingRodLength == 0)
                return 0;

            //If we are at index 0, with only possible remaining rodlength as 0 + 1 = 1, the only thing we can do is use 'RemainingRodLength' number of the rods having length 1 to make up for remaining rod length 'RemainingRodLength'.
            if(RemainingRodLength >= 1)      // Or RemainingRodLength >= 1 as index is 0. (Remaining length of rod needed to reach required length is more than 1.)
                return price[0] * (RemainingRodLength / 1);      //index + 1 = 0 + 1 = 1 or    return price[0] * RemainingRodLength
              //return price[0] * RemainingRodLength

            return INT_MIN;
        }
                
        //We are not taking the current length and instead breaking it.
        int notpick = 0 + helper(price, index - 1, RemainingRodLength);
        int pick = INT_MIN;

        int rodlength = index + 1;      // Due to 1 based indexing for rodlength
        if(rodlength <= RemainingRodLength)
            pick = price[index] + helper(price, index, RemainingRodLength - rodlength);  //Index is not decremented as there is infinite supply of rods.
            
        return max(pick, notpick);
    }

    int cutRod(int price[], int n) 
    {
        return helper(price, n - 1, n);
    }
};

/*
Memoization - 
Why it is 2d dp and not 1-D dp?
Becaues our helper function has 2 parameters which are changing for each call, they are index and RemainingRodLength. So, to track max possible prices across combination of these two variables, we will be using 2D dp.

TC - O(N * N) 
SC - O(N * N)  + O(target which is rodlength) STACK SPACE

*/
class Solution{
  public:
  
    /*
    We can think of this problem as we have to find all such rod length combinations that all those combinations sum up to 'RemainingRodLength'. And for all
    those combinations we have to find the combination which gives the maximum price.
    
    One more thing for  a rod of length 5. We can break it into 5 pieces each of size 1. This shows that there is infinite supply of rods and problem is kind of unbounded.
    
    dp[ind][len] represents till index 'ind', the maximum possible price we can get for a rod having length 'len'.
    */
    int helper(int price[], int index, int RemainingRodLength, vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            if(RemainingRodLength == 0)
                return 0;
            if(RemainingRodLength >= 1)      // Or RemainingRodLength >= 1 as index is 0. (Remaining length of rod needed to reach required length is more than 1.)
                return price[0] * (RemainingRodLength / 1);      //index + 1 = 0 + 1 = 1 or    return price[0] * RemainingRodLength
        
            return INT_MIN;
        }
        
        if(dp[index][RemainingRodLength] != -1)
            return dp[index][RemainingRodLength];
        
        //We are not taking the current length's price and instead breaking it into smaller chunks and get the maximum price from those chunks.
        int notpick = 0 + helper(price, index - 1, RemainingRodLength, dp);
        int pick = INT_MIN;

        int rodlength = index + 1;  //Due to 1 based indexing for rodlength.
        if(rodlength <= RemainingRodLength)
            pick = price[index] + helper(price, index, RemainingRodLength - rodlength, dp);  //Index is not decremented as there is infinite supply of rods.
            
        return dp[index][RemainingRodLength] = max(pick, notpick);
    }

    int cutRod(int price[], int n) 
    {
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));   
        return helper(price, n - 1, n, dp);
    }
};

/*
Tabulation
TC - O(N * N)
SC - O(N * N)
*/

class Solution{
  public:
    int cutRod(int price[], int n) 
    {
        vector<vector<int>> dp(n, vector<int> (n + 1, 0));   
        
        //Filling the first row
        for(int j = 0; j <= n; j++)
            dp[0][j] = price[0] * j;
            
        /*
        For first column, dp[i][0] which means for any index 'i' the maximum price we can get from a combined rod of length 0.
        For length 0, we can only get 0 price which is already covered as part of initialization.
        */        
            
        for(int i = 1; i < n; i++)
        {
            //Even if we loop through j = 0, we will get notpick = dp[i - 1][0] which will be 0 and pick = INT_MIN as i + 1 will always be >= 0. Therefore, resulting value will remain unchanged i.e. 0.
            for(int j = 1; j <= n; j++)
            {
                int notpick = 0 + dp[i - 1][j];
                
                int pick = INT_MIN;
                int rodlength = i + 1;
                if(rodlength <= j)
                    pick = price[i] + dp[i][j - rodlength];
                    
                dp[i][j] = max(pick, notpick);
            }
        }
        
        return dp[n - 1][n];
    }
};

/*
SpaceOptmization
TC - O(N * N)
SC - O(N)
*/

class Solution{
  public:
    int cutRod(int price[], int n) 
    {
        vector<int> dp(n + 1, 0);  
        
        //Filling the first row
        for(int j = 0; j <= n; j++)
            dp[j] = price[0] * j;
            
            
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                int notpick = 0 + dp[j];
                
                int pick = INT_MIN;
                int rodlength = i + 1;
                if(rodlength <= j)
                    pick = price[i] + dp[j - rodlength];
                    
                dp[j] = max(pick, notpick);
            }
        }
        
        return dp[n];
    }
};