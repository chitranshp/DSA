//leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int cnt = 0, n = nums.size();
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                cnt++;
                flag = true;
            }   
            else if(flag)
            {
                nums[i - cnt] = nums[i];
                nums[i] =  0;
            }
        }
            
    }
};
