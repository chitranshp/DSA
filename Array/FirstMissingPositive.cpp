// https://leetcode.com/problems/first-missing-positive/

//Each number in array will be visited exactly once. And each number will be placed in it's correct slot ATMOST once(0 in case if it's <= 0)
//Therefore Total TC O(n) + O(n) = O(n)


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int i = 0, n = nums.size();
        
        for(i = 0; i < nums.size(); i++)
            while(nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);

        for(i = 0; i < n; i++)
            if(nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};
