// https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_set <int> us;
    
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > k)
                us.erase(nums[i - k - 1]);
        
            if(us.find(nums[i]) != us.end())
                return true;
        
            us.insert(nums[i]);
            
        }
    
    return false;
    }
};
