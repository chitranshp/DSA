// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/description/

class Solution {
public:
    int averageValue(vector<int>& nums) 
    {
        int sum = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 6 == 0)
            {
                cnt++;
                sum += nums[i];
            }
        } 

        cnt = max(1, cnt);  //In case no such element is present. 
            
        return sum/cnt;
    }
};
