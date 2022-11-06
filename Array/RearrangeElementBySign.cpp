// https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int ineg = 1, ipos = 0; 
        vector<int> res(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                res[ineg] = nums[i];
                ineg += 2;
            }   
            else
            {
                res[ipos] = nums[i];
                ipos += 2;
            } 
        }

        return res;
        
    }
};
