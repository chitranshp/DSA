// https://leetcode.com/problems/delete-and-earn/

/*
Greedy solution - does not work for cases like [2, 2, 3, 3, 3, 4]
We are sorting the array, so that we don't have to search the entire array after deleting an array to search for num[i] - 1 and num[i] + 1.
With the help of sorting, we will look in one direction untill we find an element which is less than num[i] - 1.

Recursive Solution
    TC - Exponential
    SC - O(n) (Recursion Stack space)

Recursion + Memoization
    TC - O(nlogn) + O(n)
    SC - O(n) + O(n)
*/

class Solution {
public:
    int helper(vector<int> &nums, int index, vector<int> &dp)
    {
        if(index < 0)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int notpick = helper(nums, index - 1, dp);
        int pick = nums[index];

        int i = index - 1;
        //While previous element is same as current element, include it in the current sum
        while(i >= 0 && nums[index] == nums[i])
        {
            pick += nums[i];
            i--;
        }

        //While previous element is same as current element - 1, skip it. Then it won't be used for subcalls which is effectively same as deleting it.
        //We are not bothered about elements equal to nums[index] + 1, as they wont be used in subsequent calls as the array is sorted. So, they also will be automatically skipped.
        while(i >= 0 && nums[index] - 1 == nums[i])
            i--;

        pick += helper(nums, i, dp);
        return dp[index] = max(pick, notpick);
    }

    int deleteAndEarn(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        sort(nums.begin(), nums.end());
        return helper(nums, n - 1, dp);
    }
};