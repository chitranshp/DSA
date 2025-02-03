// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/

/*
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 1;
        int incLength = 1, decLength = 1;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] < nums[i + 1])
            {
                incLength++;
                decLength = 1;
            }
            else if(nums[i] > nums[i + 1])
            {
                incLength = 1;
                decLength++;
            }
            else
            {
                incLength = 1;
                decLength = 1;
            }

            maxLength = max(maxLength, max(incLength, decLength));
        }

        return maxLength;
    }
};
