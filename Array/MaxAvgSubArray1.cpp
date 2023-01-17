// https://leetcode.com/problems/maximum-average-subarray-i/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        double globalsum = INT_MIN, currsum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(i < k)
                currsum += nums[i];
            else
            {
                globalsum = max(currsum, globalsum);            
                currsum = currsum + nums[i] - nums[i - k];      
            }
        }

        globalsum = max(currsum, globalsum);    //For i = n - 1, globalsum won't be updated inside loop. Therefore, checking here.

        return globalsum / k;
    }
};
