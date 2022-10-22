//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int low = 0, high = nums.size() - 1, mid;
        
        while(low < high)
        {
            mid = low + (high - low)/2;
            
            //if(nums[low] < nums[high])
                //return low;
            
            if(nums[mid] > nums[high])
                low = mid + 1;              //Excluding mid, as we know it is greater then num[high],                                                       It can't be min
            else
                high = mid;                 //num[mid] we don't have any idea. it may be <=
            
        }
        
        return nums[low];
    }
};
