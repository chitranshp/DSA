// https://leetcode.com/problems/min-cost-climbing-stairs/description/

/*
Here, we have two starting points stair 0 and 1. Whereas one fixed ending point which is stair n + 1.
Approach 2: We will recursively find the min cost from n + 1th(n as we are using 0 indexed array) to either of 0th step of 1th step.
                f(n) = F2(n + 1)
At each stair, we will have two options either to go back 2 steps or 1 steps. For n + 1th stair there is no cost as we are not moving anywhere from it. So, we will take 0 as the cost for that one.
Only 1 initial call will be required in this approach

Approach 2: If we are not starting from (n + 1)th stair, we will have two start from either of these two
    f(n) = min(F2(n - 1), F2(n - 2))
If we are memoizing this approach, the TC will still remain O(n) as we will be using the precalculated dp vector, instead of doing it again recursively.
Base cases will be for index == 0 || index == 1 return 0 as we have reached the required point.
Each dp[i] will be already filled with min cost achievalbe from either index 0 or index 1.

Approach 3: Start from index 0 till index becomes equal to n(Base case, return 0)
Each dp[i] will store the min cost to reach stair 'n + 1' from stair 'i + 1'
AND AT THE END RETURN min of dp[0] and dp[1].
Only 1 initial call will be required in this approach

Note: In both cases, F2 function will remain unchanged
        F2(i) = cost[i] + min(f(i - 1), f(i - 2))

TC - O(n)
SC - O(n)
*/

class Solution {
    private int helper(int[] cost, int index, int[] dp) {

        if(index == 0 || index == 1)
            return cost[index];

        if(dp[index] != -1)
            return dp[index];

        int c = (index < cost.length ? cost[index]: 0);

        return dp[index] = c + Math.min(helper(cost, index - 1, dp), helper(cost, index - 2, dp));
    }
    
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;

        //Our actual target is stair 'n + 1' (If we are counting from 1) not stair 'n'.
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);

        // n for n + 1 (0 based indexing)
        return helper(cost, n, dp);
    }
}

/*
Tabulation
TC - O(n)
SC - O(n)
*/
class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost)
        {
            int n = cost.size();

        //Our actual target is stair 'n + 1' (If we are counting from 1) not stair 'n'.
            vector<int> dp(n + 2, 0);
            
            dp[n + 1] = INT_MAX; //Max
            dp[n] = 0;

            for(int i = n - 1; i >= 0; i--)
            {
                dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
            }
            
            
            return min(dp[0], dp[1]);
        }
}

/*
Space Optimization
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();

        //Our actual target is stair 'n + 1' (If we are counting from 1) not stair 'n'.
        
        int prev2 = cost[0]; //Max
        int prev1 = cost[1];
        int curr = 0;

        for(int i = 2; i <= n; i++)
        {
            curr = min(prev1, prev2);
            if(i != n)
                curr += cost[i];
                
            prev2 = prev1;
            prev1 = curr;
        }
        
        return min(prev1, prev2);
    }
};