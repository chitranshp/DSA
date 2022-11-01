// https://leetcode.com/problems/single-element-in-a-sorted-array/

//  For odd index x, x ^ 1 = x - 1
//  For even index x, x ^ 1 = x + 1


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int mid = nums.size()/2;
        int low = 0, high = nums.size() - 1;
        int partnerIndex, i;
        
        while(low < high)
        {
            mid = low + (high - low)/2;
            partnerIndex = mid ^ 1;
            
            if(nums[mid] == nums[partnerIndex])
                low = mid + 1;
            else
                high = mid;
        }
        
        return nums[low];
    }
};
