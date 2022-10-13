//https://leetcode.com/problems/most-frequent-even-element/

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) 
    {
        unordered_map<int, int> um;
        int candidate = -1;
        int maxfreq = -1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 == 0)
            {
                
                if(maxfreq < ++um[nums[i]] || (maxfreq == um[nums[i]] && nums[i] < candidate))
                {
                    maxfreq = um[nums[i]];
                    candidate = nums[i];
                }
            }
        }
        return candidate;
    }
    
};