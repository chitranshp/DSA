// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

/*
TC - O(nlogn + n)
SC - O(n)
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        int n = nums.size(), pairsum = INT_MIN;
        int i = 0;
        sort(nums.begin(), nums.end());

        for(i = 0; i < n/2; i++)
            pairsum = max(pairsum, nums[i] + nums[n - i - 1]);

        return pairsum;
    }
};