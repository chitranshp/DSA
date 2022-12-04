// https://leetcode.com/problems/minimum-average-difference/description/

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        vector<long long int> prefixsum(nums.size(), 0);
        int i = 0, n = nums.size(), minval = INT_MAX, index = 0;

        prefixsum[0] = nums[0];
        for(i = 1; i < n; i++)
            prefixsum[i] = nums[i] + prefixsum[i - 1];
            
        for(i = 0; i < n - 1; i++)
        {
            long sum1 = round(prefixsum[i]);
            long sum2 = round(prefixsum[n -1] - prefixsum[i]);          //For last element denominator will become 0 for the right portion. So, we handle that case separately later.
            nums[i] = abs(sum1 / (i + 1) - sum2 / (n - i - 1));

            if(nums[i] < minval)
            {
                minval = nums[i];
                index = i;
            }
        }

        if(round(prefixsum[n - 1]/n) < minval)          //For last element
            return n - 1;
        
        return index;
    }
};
