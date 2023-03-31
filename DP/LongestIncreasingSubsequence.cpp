// https://leetcode.com/problems/longest-increasing-subsequence/description/

/*
Recursion - We will go through all the valid subsequences(which are increasing) and count them.
For each element we will have a choice whether to include that element in our subsequence or whether to exclude.
And in the case of inclusion, we will have to check one more thing i.e. whether inclusion of that element is in accordance with our problem statement or not.
This means before including any element, we need to check whether that element is greater then the previous element in that subsequence.
To check this condition, we therefore also need to carry the previous element of the subsequence or it's index
TC - O(2 ^ n)
SC - O(n)
*/

class Solution {
public:
    int helper(vector<int>& nums, int index, int prevind) 
    {
        //When we have exhausted the array
        if(index >= nums.size())
            return 0;

        int pick = 0;
        if(prevind == -1 || nums[index] > nums[prevind])
            pick = 1 + helper(nums, index + 1, index);

        int notpick = helper(nums, index + 1, prevind);

        return max(pick, notpick);;
    }

    int lengthOfLIS(vector<int>& nums, int index = 0) 
    {
        int n = nums.size();
        return helper(nums, 0, -1, dp);
    }
};

/*
Memoization
dp[i][prevind] = This represents the length of LIS from index 'i' with it's previous term being nums[prevind] (nums[prevind] is also a part of LIS but it's value won't be part of dp[i][prevind])

Note: In our recursion apprach value of prevind was in range [-1, n - 1]. 
With array, we can't use negative indexing, so either we use another positive index outside of range of prev [0 , n - 1] to indicate there is no previous term for ex. 'n + 1' or we can use index shifitng.


We can map prevind of nums to dp[i][prevind + 1] ie -1 -> 0 , nums[0] as prev term will be mapped to dp[i][0 + 1].
Note: Only dp vector second dimension is shifted by 1. nums vector is still 0-indexed.
TC - O(n * n)
SC - O(n * n) + O(n)
*/

class Solution {
public:
    int helper(vector<int>& nums, int index, int prevind, vector<vector<int>> &dp) 
    {
        //When we have exhausted the array
        if(index >= nums.size())
            return 0;

        if(dp[index][prevind + 1] != -1)
            return dp[index][prevind + 1];

        int pick = 0;
        //dp[i][prevind] represents LIS from index 'i' till end of array with nums[prevind] as it's previous index
        if(prevind == -1 || nums[index] > nums[prevind])
            pick = 1 + helper(nums, index + 1, index, dp);

        int notpick = helper(nums, index + 1, prevind, dp);

        return dp[index][prevind + 1] = max(pick, notpick);;
    }

    int lengthOfLIS(vector<int>& nums, int index = 0) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return helper(nums, 0, -1, dp);
    }
};

/*
Remember dp is index shifted, helper(i + 1, prev) translates to dp[i + 1][prev + 1]
Memoization
TC - O(n * n)
SC - O(n * n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int index = 0) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        for(int index = n - 1; index >= 0; index--)
        {
            //Previndex by definition is an index which is somewhere before index. 
            //It can never be ahead of index. Therefore, we have taken the inner loop from [index - 1, -1] instead of [n - 1, -1]. Those extra calculations are completely unnecessary and those cells will contain 0 anyhow.
            //Even if we have taken loop in reverse order, results would still remain same.
            for(int prevind = index - 1; prevind >= -1; prevind--)
            {
                int pick = 0;
                if(prevind == -1 || nums[index] > nums[prevind])
                    pick = 1 + dp[index + 1][index + 1];
                
                //dp is index shifted. To counter for that we have taken dp[index + 1][prevind + 1]
                int notpick = dp[index + 1][prevind + 1];

                dp[index][prevind + 1] = max(pick, notpick);
            }
        }

        return dp[0][0];
    }
};

/*
SpaceOptimization
TC - O(n * n)
SC - O(n) + O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int index = 0) 
    {
        int n = nums.size();
        //vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        vector<int> ahead(n + 1, 0), curr(n + 1, 0);

        for(int index = n - 1; index >= 0; index--)
        {
            //Previndex by definition is an index which is somewhere before index. It can never be ahead of index. Therefore, we have taken the inner loop from [index - 1, -1] instead of [n - 1, -1]. Those extra calculations are completely unnecessary and those cells will contain 0 anyhow.
            for(int prevind = index - 1; prevind >= -1; prevind--)
            {
                int pick = 0;
                if(prevind == -1 || nums[index] > nums[prevind])
                    pick = 1 + ahead[index + 1];
                
                //dp is index shifted. To counter for that we have taken dp[index + 1][prevind + 1]
                int notpick = ahead[prevind + 1];

                curr[prevind + 1] = max(pick, notpick);
            }

            ahead = curr;
        }

        return curr[0];
    }
};