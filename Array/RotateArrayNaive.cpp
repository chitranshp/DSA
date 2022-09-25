//https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int index, n = nums.size();
        vector<int> temp(n, 0);
        if(n <= 0)
            return;
        while(k > n)
            k = k - n;
        
        for(index = 0; index < n; index++)
        {
            temp[index] = nums[(n + index - k) % n];
        }
        nums = temp;
    }
};