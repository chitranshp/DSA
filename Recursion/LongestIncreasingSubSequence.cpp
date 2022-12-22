// https://leetcode.com/problems/longest-increasing-subsequence/

// O(2^n) TC - TLE
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int index = 0, int prev = INT_MIN) 
    {
        if(index >= nums.size())
            return 0;

        int pick = 0, notpick = 0;

        // If(nums[index] > prev) then it's value will be true(1) else it will be 0
        pick = (nums[index] > prev) + lengthOfLIS(nums, index + 1, max(prev, nums[index]));
        notpick = lengthOfLIS(nums, index + 1, prev);
        
        return max(pick, notpick);
    }
};
