// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> visited(nums.size() + 1, 0);
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            visited[nums[i]] = 1;
        }

        for(int i = 1; i <= nums.size(); i++)
            if(!visited[i])
                result.push_back(i);

        return result;
    }
};
