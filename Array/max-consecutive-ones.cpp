//https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int globalmax = 0, currmax = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                currmax++;
                if(currmax > globalmax)
                    globalmax = currmax;
            }
            else
                currmax = 0;
        }
        return globalmax;
    }
};
