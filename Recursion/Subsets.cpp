//https://leetcode.com/problems/subsets/

class Solution {
public:
    void generatesubsets(int index, vector<int> &nums,vector<int> &temp, vector<vector<int>> &res)
    {
        if(index >= nums.size())
        {
            res.push_back(temp);
            return;
        }
        
        generatesubsets(index + 1, nums, temp, res);
        temp.push_back(nums[index]);
        generatesubsets(index + 1, nums, temp, res);
        temp.pop_back();
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        generatesubsets(0, nums,temp, res);
        return res;
    }
};
