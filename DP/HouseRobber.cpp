// https://leetcode.com/problems/house-robber/description/

/* Recursion - TLE */
class Solution {
public:
    /* 
    *At each house, the robber has two choices to rob it or not to rob it and choose a neighbouring house
    * Each step = (Rob current ith house + Collect loot from previous i -2 th house) or (Dont rob ith house and rob i - 1 th house)
    Recursive Equation = Max(First option, Second option)

    */

    int profithelper(vector<int> &nums, int index)
    {
        if(index < 0)
            return 0;

                                                   //Adding the loot of current house
        return max(profithelper(nums, index - 2) + nums[index], profithelper(nums, index - 1)); //No loot is added for the second call as when we decide to rob i - 1 th house, we must skip ith house as to not alert security systems.

    }

    int rob(vector<int>& nums) 
    {
        return profithelper(nums, nums.size() - 1);
    }
};



/* Recursion + Memoization (Top Down DP) having TC O(n) and SC O(N) */
    int profithelper(vector<int> &nums, vector<int> &loot, int index)
    {
        if(index < 0)
            return 0;

        if(loot[index] == -1)
            loot[index] = max(profithelper(nums, loot, index - 2) + nums[index], profithelper(nums, loot, index - 1));          //No loot is added for the second call as when we decide to rob i - 1 th house, we must skip ith house as to not alert security systems.

        return loot[index];                         
    }

    int rob(vector<int>& nums) 
    {
        vector<int> loot(nums.size(), -1);
        return profithelper(nums, loot, nums.size() - 1);
    }
};
