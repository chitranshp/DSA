// https://leetcode.com/problems/sign-of-the-product-of-an-array/

/*
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        int sign = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= 1)
                sign = sign * 1;
            else if(nums[i] == 0)
                return 0;
            else
                sign = sign * -1;          
        }

        return sign;
    }
};