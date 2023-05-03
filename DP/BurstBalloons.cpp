// https://leetcode.com/problems/burst-balloons/

/*
Recursion
TC - Exponential
SC - O(n) for recursion stack

We are given an array: {b1, b2, b3, b4, b5, b6}. Each element of the given array is representing a balloon. Now, if we burst the b4, we will get a total of (b3*b4*b5) coins. After bursting b4, we are left with the left sub-problem {b1, b2, b3} and the right sub-problem {b5, b6} to solve.

If we burst balloons in this manner, the problems will be having a dependancy on the other problem.
Let’s understand the reason behind this. Imagine, at first we burst the balloon b4. Then, we are left with the array:  {b1, b2, b3, b5, b6}. Now, if we try to burst b3, it will be dependent on b5. Similarly, if we try to burst b5, it will be dependent on b3. Similarly, we can observe the same dependency in the case of other elements as well. So, we cannot solve the subproblems {b1, b2, b3} and {b4, b5} independently as they are dependent on each other.

we will just try to think in the opposite way. First, we tried to find out a balloon that we will burst first. BUT now, we will first try to find that balloon which we will burst last.

Note: The intuition is to first find the last balloon, then the second last, and so on. This is the sequence we need to follow to solve this problem.

We are given an array: {b1, b2, b3, b4, b5, b6}. Assume, b4 be the last balloon we will burst. Then we can surely say, the total no. of coins we can get by bursting the balloon b4 is (1*b4*1). Now, we get two subproblems as usual: {b1, b2, b3} and {b5, b6}, and while choosing the second last balloon, we can ensure that b4 exists while bursting the second last balloon. If the second last balloon belongs to the 1st sub-problem i.e. {b1, b2, b3}, it will be only dependent on the last balloon i.e. b4 as the rightmost element will be b4. Similarly,  if the second last balloon belongs to the 2nd sub-problem i.e. {b5, b6}, it will also be dependent only on the last balloon i.e. b4 as the leftmost element will be b4. The following illustration will clarify the concept:

Now, we can clearly observe the subproblems are no anymore dependent on each other.
*/

class Solution {
public:
    int helper(vector<int>& nums, int i, int j, vector<vector<int>> & dp) 
    {
        /*
        If we don't keep i + 1 == j here, then for the call helper(0, 1)
                    index = 0 + 1 = 1 => index is not less than j.
                Therefore loop won't be executed even once and res = INT_MIN will be returned which is wrong and will make the whole call sum approx INT_MIN

        To get rid of that, we can add a base condition if i + 1 == j return 0
                                            or
        Initialize res with 0 instead of INT_MIN
        */
        if(i > j || i + 1 == j) 
            return 0;
        
        int res = -1e7;         //If we set res = 0, we can avoid adding another base condition for i + 1 == j
        for(int index = i + 1; index < j; index++)  
        {
            int val = nums[i] * nums[index] * nums[j] + helper(nums, i, index) + helper(nums, index, j0); 
            res = max(val, res);
        }

        return res;
    }

    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        return helper(nums, 0, nums.size() - 1);
    }
};

/*
Memoization 
TC - O(n * n * n)
SC - O(n * n) + O(n)
*/

class Solution {
public:
    int helper(vector<int>& nums, int i, int j, vector<vector<int>> & dp) 
    {
        if(i > j || i + 1 == j) 
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = -1e7;
        for(int index = i + 1; index < j; index++)
        {
            int val = nums[i] * nums[index] * nums[j] + helper(nums, i, index, dp) + helper(nums, index, j, dp);
            res = max(val, res);
        }

        return dp[i][j] = res;
    }

    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
           
        return helper(nums, 0, nums.size() - 1, dp);
    }
};

/*
Tabulation
TC - O(n * n * n)
SC - O(n * n)
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), 0));

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(i > j) 
                    continue;

                int res = 0;
                for(int index = i + 1; index < j; index++)
                {
                    int val = nums[i] * nums[index] * nums[j] + dp[i][index] + dp[index][j];
                    res = max(val, res);
                }

                dp[i][j] = res;
            }
        }
        
        return dp[0][nums.size() - 1];
    }
};