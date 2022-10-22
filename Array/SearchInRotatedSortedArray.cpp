//https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    //At any time, one of two halves will be sorted. Utilize that half to find the half in which target half.
    int search(vector<int>& nums, int target) 
    {
        int low = 0, high = nums.size() - 1, mid;
        
        while(low <= high)
        {
            mid = (low + high)>>1;
            
            if(nums[mid] == target)
                return mid;
            
            //If left half is sorted
            if(nums[low] <= nums[mid])
            {
                if(nums[low] <= target && nums[mid] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
//means right half is sorted. Check if it is present in right half, if not eliminate right half. Then divide and search in left half.
            else
            {
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        
        return -1;
    }
};
