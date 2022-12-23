// https://leetcode.com/problems/find-pivot-index/description/

class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int pivot = -1;
        int lsum = 0, rsum = 0;
        
        for(int i = 0; i < nums.size(); i++)
            rsum +=nums[i];

        for(int i = 0; i < nums.size(); lsum += nums[i++])    //or in code body place this If(i > 0) lsum += nums[i - 1];
        {
            rsum -= nums[i];
            
            if(lsum == rsum)
            {
                pivot = i;
                break;
            }
                
        }

        return pivot;
    }
};
