// https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    bool canJump(vector<int>& nums, int index = 0) 
    {
        int n = nums.size();
        int step = nums[0];
        
        for(int i = 1; i < n; i++)      //Starting from 1 as pos 0 is always reachable even if nums[0] is 0.
        {
            --step;

            if(step < 0)
                return false;
            
            if(nums[i] > step)
                step = nums[i];
        }

        return true;

    }
};

// Another approach

/*
class Solution {
public:
    bool canJump(vector<int>& nums, int index = 0) 
    {
        int n = nums.size();
        int last = n - 1;
        
        for(int i = n - 2; i >= 0; i--)
            if(i + nums[i] >= last)
                last = i;

        return last == 0;


    }
};
*/
