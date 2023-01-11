// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int n = nums.size();
        int firstpos = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();  // first >= 1 or first positive number
        int firstzero = lower_bound(nums.begin(), nums.end(), 0) - nums.begin(); // first >= 0 eithre first zero or first +ve number

        return max(firstzero, n - firstpos);
    }
};
