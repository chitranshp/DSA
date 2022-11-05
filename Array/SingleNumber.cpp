// https://leetcode.com/problems/single-number/
// O(n) TC and O(1) SC


class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++)
            ans ^= nums[i];

        return ans;

    }
};


// O(n) SC
/*
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int, int> m;
        int ans;
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        
        for(auto i: m)
            if(i.second == 1)
            {
                ans = i.first;
                break;
            }
                
        
        return ans;
        
    }

*/
