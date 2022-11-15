// https://leetcode.com/problems/subsets-ii/


//Naive version with extra DS(set)

/*
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
*/

//Optimised Version

class Solution {
public:
    void subsetHelper(vector<int> &nums, vector<vector<int>> &res, int index, vector<int> temp)
    {
        res.push_back(temp);    //[],[1], [1, 2]

        for(int i = index; i < nums.size(); i++)
        {
            if(i != index && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            subsetHelper(nums, res, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        subsetHelper(nums, res, 0, temp);
        return res;
    }
};

