// https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    void subsetHelper(vector<int> &nums, set<vector<int>> &res, int index, vector<int> temp)
    {
        if(index >= nums.size())
        {
            res.insert(temp);
            return;
        }

        //Pick
        temp.push_back(nums[index]);
        subsetHelper(nums, res, index + 1, temp);
        temp.pop_back();
        //Not Pick
        subsetHelper(nums, res, index + 1, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        subsetHelper(nums, res, 0, temp);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
