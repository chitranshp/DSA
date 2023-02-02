// https://leetcode.com/problems/climbing-stairs/submissions/888367693/

class Solution {
public:

// TOP DOWN - Recursive appraoch TC O(2 ^ N) SC O(N) for stack

/*************** We can also think it as, at every single stair we have two options whether to take one step or two steps. So, at each step we will try both of these. ****************/

    int helper(int index)
    {
        //Base case. While travelling top to down (n to 0), if we are reaching step 0. That means, that path(sequence of steps is valid as per question). Therefore to count that way we are returning 1.
        if(index == 0)
            return 1;

        if(index < 0)
            return 0;

        //If we are standing at any other stair, there is only 2 steps/things we can do as per question. That is either we can jump 1 step or we can jump 2 step.
        int left = helper(index - 1);           //Left recursion call
        int right = helper(index - 2);          //Right recursion call

        return left + right;
        // This is same as recurrence equation of fibonacci sequence
        // return helper(index - 1) + helper(index - 2) 
    }

//Recursion + Memoization (Top Down DP)
    int helper2(vector<int>& dp, int index)
    {
        if(index == 0)
            return 1;
        
        if(index < 0)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        return dp[index] = helper2(dp, index - 1) + helper2(dp, index - 2);
    }

//BOTTOM UP APPROACH - Based on insights derived form TOP DOWN APPROACH.  TC O(N) SC O(N)
    int climbStairs(int n) 
    {
        vector<int> dp(n + 1, -1);

        if(n <= 2)
            return n;
            
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;      //After n = 2, it follows the fibonacci pattern.

        for(int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n];
        //Uncomment below line for top - down Recursion based solution.
        //return helper(n);  

        //Uncomment below line for Top - down Recurison + Memoization approach
        //return helper2(dp, n);   
    }

//SPACE OPTIMAL VERSION - DP + OPTIMIZATION TC O(N) SC O(1)
    int climbstairs2(int n)
    {
        int first = 1, second = 2, third;

        for(int i = 3; i <= n; i++)         //We are staring from index 3, so we only need last 2 values ie index - 2 and index 1
        {
            third = first + second;
            first = second;
            second = third;
        }

        return third;
    }
};
