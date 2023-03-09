// https://leetcode.com/problems/target-sum/

/*
Approach 1: Recursion
TC - O(2 ^ N)
SC - O(N)
*/
class Solution {
public:
    int helper(vector<int>& nums, int target, int index)
    {
        if(index == -1)
        {
            /*
            int ans = 0;
            if(target - nums[0] == 0)
                ans++;
            if(target + nums[0] == 0)
                ans++;

            return ans;
            */
            return target == 0;
        }

        int a = helper(nums, target + nums[index], index - 1);
        int b = 0;
        
        b = helper(nums, target - nums[index], index - 1);

        return a + b;
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return helper(nums, target, nums.size() - 1);
    }
};