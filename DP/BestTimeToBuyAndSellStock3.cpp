// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*
Recursion
The only difference between this and the previous variant of this problem is in this we have given number of transaction (2) that we are free to perform to get the maximum profit.
Transaction -> Meaning one buy AND one sell (In this order only)

We can just introduce another variable transactioncap with initial value 2 and decrement it's value whenever we have made a sale. We are already using 'CanBuy' variable to keep track of whether we can perform a buy or sell operation or not. Now, we will further introduce this transaction cap to it.
Note: In recursion, we are going from 0 -> n - 1 as if we go in reverse order, it will buy in future and sell on a past day which is not a valid transaction.
TC - Exponential
SC - O(n)
*/

class Solution {
public:
    int helper(vector<int>& prices, int i, int canBuy, int transactioncap)
    {
        if(i == prices.size || transactioncap == 0)
            return 0; //No more profit can be extracted;

        int profit = 0;

        if(canBuy)
        {
            profit = max(-prices[i] + helper(prices, i + 1, 0, transactioncap), 0 + helper(prices, i + 1, 1, transactioncap));          
        }
        else
        {
            //Whenver we perform a sell operation that means one buy and then one sell operation has been done ie. one transaction has been done. Therefore, we will reduce the transaction by 1.
            profit = max(prices[i] + helper(prices, i + 1, 1, transactioncap - 1), 0 + helper(prices, i + 1, 0, transactioncap));
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        int transactioncap = 2;
        int n = prices.size();
        int canBuy = 1;
        return helper(prices, 0, canBuy, transactioncap);
    }
};

/*
Memoization - Since, here are three variables which are changing across recursion calls, we will use a 3-d dp vector.
TC - O(n * 2 * transactioncap)
SC - O(n * 2 * transactioncap) + O(n)
*/

class Solution {
public:
    int helper(vector<int>& prices, int i, int canBuy, int transactioncap, vector<vector<vector<int>>> &dp)
    {
        if(i == prices.size() || transactioncap == 0)
        {
            return 0; //No more profit can be extracted;
        }

        if(dp[i][canBuy][transactioncap] != -1)
            return dp[i][canBuy][transactioncap];

        int profit = 0;

        if(canBuy)
        {
            profit = max(-prices[i] + helper(prices, i + 1, 0, transactioncap, dp), 0 + helper(prices, i + 1, 1, transactioncap, dp));    
        }
        else
        {
            profit = max(prices[i] + helper(prices, i + 1, 1, transactioncap - 1, dp), 0 + helper(prices, i + 1, 0, transactioncap, dp));
        }

        return dp[i][canBuy][transactioncap] = profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        int transactioncap = 2;
        int n = prices.size();
        int canBuy = 1;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (transactioncap + 1, -1)));
        return helper(prices, 0, canBuy, transactioncap, dp);
    }
};

/*
Tabulation - Since, in recursion we went from 0 to n - 1, in tabulation we will go from n - 1 to 0
TC - O(n * 2 * (transactioncap + 1))
SC - O(n * 2 * (transactioncap + 1))
*/

class Solution {
public:
    int helper(vector<int>& prices, int i, int canBuy, int transactioncap, vector<vector<vector<int>>> &dp)
    {
        if(i == prices.size() || transactioncap == 0)
        {
            return 0; //No more profit can be extracted or transaction cap has been achieved;
        }

        if(dp[i][canBuy][transactioncap] != -1)
            return dp[i][canBuy][transactioncap];

        int profit = 0;

        if(canBuy)
        {
            profit = max(-prices[i] + helper(prices, i + 1, 0, transactioncap, dp), 0 + helper(prices, i + 1, 1, transactioncap, dp));
            
        }
        else
        {
            profit = max(prices[i] + helper(prices, i + 1, 1, transactioncap - 1, dp), 0 + helper(prices, i + 1, 0, transactioncap, dp));
        }

        return dp[i][canBuy][transactioncap] = profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int transactioncap = 2;
        int n = prices.size();
        int canBuy = 1;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (transactioncap + 1, 0)));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int cb = 0; cb < 2; cb++)       //We are only using canbuy values 0 and 1.
            {
                for(int cap = 1; cap <= 2; cap++)   //If we go from 0 to 2, we will have to uncomment first if condition. Since, it is redundant it's better to avoid it.
                {
                    /*
                    Another base case of for dp[n] = {0} row is not written explicitly as it is redundant. 

                    This is redundant because as part of initialization, we have already initialized whole table with value 0. We can just constraint third loop to run from cap = 1 to cap <= 2.
                    if(cap == 0 || i == n)  // profit = dp[i + 1]
                    {
                        dp[i][cb][cap] = 0;
                        continue;
                    }
                    */

                    int profit = 0;

                    if(cb)
                    {
                        profit = max(-prices[i] + dp[i + 1][0][cap], 0 + dp[i + 1][1][cap]);    //If i = n - 1, then i + 1 will be n. Therefore, size of dp must be dp[n][k + 1]
                        
                    }
                    else
                    {
                        profit = max(prices[i] + dp[i + 1][1][cap - 1], 0 + dp[i + 1][0][cap]);
                    }

                    dp[i][cb][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};

/*
SpaceOptimization - We can see that dp values of row dp[i] are dependendent on dp[i + 1] row. Instead of one 3d vector, we can declare two 2d vectors each of size [2][3].
TC - O(n * 2 * 3)
SC - O(2 * 3) We can say it as O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int transactioncap = 2;
        int n = prices.size();
        int canBuy = 1; //For tabulation this variable does not matter as inside our loop we will be anyhow looping for entire range of canbuy [0,1]. This is not a dependency for tabulation approach.
        //vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (transactioncap + 1, 0)));
        vector<vector<int>> after(2, vector<int> (3, 0)), curr(2, vector<int> (3, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int cb = 0; cb < 2; cb++)
            {
                for(int cap = 1; cap <= 2; cap++)
                {
                    /*
                    This is redundant because as part of initialization, we have already initialized whole table with value 0. We can just constraint third loop to run from cap = 1 to cap <= 2.
                    if(cap == 0)
                    {
                        dp[i][cb][cap] = 0;
                        continue;
                    }
                    */

                    int profit = 0;

                    if(cb)
                    {
                        profit = max(-prices[i] + after[0][cap], 0 + after[1][cap]);
                        
                    }
                    else
                    {
                        profit = max(prices[i] + after[1][cap - 1], 0 + after[0][cap]);
                    }

                    curr[cb][cap] = profit;
                }

                after = curr;
            }
        }

        return curr[1][2];
    }
};

/*
Further Space Optimization
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int transactioncap = 2;
        int n = prices.size();
        int canBuy = 1; 
        vector<vector<int>> dp(2, vector<int> (3, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int cb = 0; cb < 2; cb++)
            {
                for(int cap = 2; cap >= 1; cap--)
                {
                    int profit = 0;

                    if(cb)
                    {
                        profit = max(-prices[i] + dp[0][cap], 0 + dp[1][cap]);
                        
                    }
                    else
                    {
                        profit = max(prices[i] + dp[1][cap - 1], 0 + dp[0][cap]);
                    }

                    dp[cb][cap] = profit;
                }
            }
        }

        return dp[1][2];
    }
};

/*
Approach 2:
We are given a transaction cap of 2 which means 
            B   s   B   S
            0   1   2   3
We can code it in such a way that transactioncap = 2 * 2(2 - represents buy and sell which make up one transaction)
And we can ignore the canBuy variable. Instead of that we can use this modified transactionCap to tell whether we can perform buy or sell.
If transactionCap is even we can perform a buy, if it is odd we can perform a sell. If it is < 0 or > 3, that means we have exhausted available transactions.
TC - O(n * 4)
SC - O(4) which is approximately equal to 4.
*/

/*
Approach 2 - Memoization
TC - O(n * 4)
SC - O(n)
*/

class Solution {
public:
    int helper(vector<int> &prices, int i, int cap, vector<vector<int>> &dp)
    {
        if(i == prices.size() || cap == 0)
            return 0;

        if(dp[i][cap] != -1)
            return dp[i][cap];

        int profit = 0;
        if(cap % 2 == 0)    //Buy
        {
            profit = max(-prices[i] + helper(prices, i + 1, cap - 1, dp), 0 + helper(prices, i + 1, cap, dp));
        }
        else
        {
            profit = max(prices[i] + helper(prices, i + 1, cap - 1, dp), 0 + helper(prices, i + 1, cap, dp));
        }

        return dp[i][cap] = profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int transactioncap = 2 * 2;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (transactioncap + 1, -1));
        return helper(prices, 0, transactioncap, dp);
    }
};

/*
Tabulation
*/

class Solution {
public:
    int helper(vector<int> &prices, int i, int cap, vector<vector<int>> &dp)
    {
        if(i == prices.size() || cap == 0)
            return 0;

        if(dp[i][cap] != -1)
            return dp[i][cap];

        int profit = 0;
        if(cap % 2 == 0)    //Buy
        {
            profit = max(-prices[i] + helper(prices, i + 1, cap - 1, dp), 0 + helper(prices, i + 1, cap, dp));
        }
        else
        {
            profit = max(prices[i] + helper(prices, i + 1, cap - 1, dp), 0 + helper(prices, i + 1, cap, dp));
        }

        return dp[i][cap] = profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int transactioncap = 2 * 2;
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (transactioncap + 1, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int cap = 1; cap <= 4; cap++)
            {
                //For i == n or cap == 0, dp[i][cap] = 0 is covered in initialization.
                int profit = 0;
                if(cap % 2 == 0)    //Buy
                {
                    profit = max(-prices[i] + dp[i + 1][cap - 1], 0 + dp[i + 1][cap]);
                }
                else
                {
                    profit = max(prices[i] + dp[i + 1][cap - 1], 0 + dp[i + 1][cap]);
                }

                dp[i][cap] = profit;
            }
        }
        return dp[0][4];
    }
};

/*
SpaceOptimization
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int transactioncap = 2 * 2;
        int n = prices.size();
        vector<int> after(transactioncap + 1, 0), curr(transactioncap + 1, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            for(int cap = 1; cap <= 4; cap++)
            {
                //For i == n or cap == 0, dp[i][cap] = 0 is covered in initialization.
                int profit = 0;
                if(cap % 2 == 0)    //Buy
                {
                    profit = max(-prices[i] + after[cap - 1], 0 + after[cap]);
                }
                else
                {
                    profit = max(prices[i] + after[cap - 1], 0 + after[cap]);
                }

                curr[cap] = profit;
            }

            after = curr;
        }

        return curr[4];
    }
};

/* Further space optimization - We are using only above and values to left of above cell. So if we fill from right to left we can use only 1 row to store for both*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int transactioncap = 2 * 2;
        int n = prices.size();
        vector<int> after(transactioncap + 1, 0), curr(transactioncap + 1, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            for(int cap = 1; cap <= 4; cap++)
            {
                //For i == n or cap == 0, dp[i][cap] = 0 is covered in initialization.
                int profit = 0;
                if(cap % 2 == 0)    //Buy
                {
                    profit = max(-prices[i] + after[cap - 1], 0 + after[cap]);
                }
                else
                {
                    profit = max(prices[i] + after[cap - 1], 0 + after[cap]);
                }

                curr[cap] = profit;
            }

            after = curr;
        }
        return curr[4];
    }
};