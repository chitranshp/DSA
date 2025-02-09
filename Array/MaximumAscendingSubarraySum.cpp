//https://leetcode.com/problems/maximum-ascending-subarray-sum/

/*
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0], curr = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            // Sliding window. Either add current element to existing window or Start a new window from current element based on condition
            curr = (nums[i - 1] < nums[i])? curr + nums[i]: nums[i];
            res = max(res, curr);
        }

        return res;
    }
};
