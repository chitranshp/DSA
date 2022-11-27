// https://leetcode.com/problems/monotonic-array/description/
// O(n)

class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        //0 -> Ascending 1 -> Descending
        bool order = (nums[0] < nums[nums.size() - 1])? 0:1;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(order == 0 && nums[i] > nums[i + 1])
                return false;

            if(order == 1 && nums[i] < nums[i + 1])
                return false;
        }

        return true;
    }
};
