// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void helperfun(int index, vector<int> &candidates, vector<int> temp, vector<vector<int>> &ans, int target)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(target < 0 || index >= candidates.size())
        { 
            return;
        }

        if(candidates[index] <= target)
        {
            temp.push_back(candidates[index]);
            helperfun(index, candidates, temp, ans, target - candidates[index]);
            temp.pop_back();    //Backtrack
        }
        
        helperfun(index + 1, candidates, temp, ans, target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        helperfun(0, candidates, temp, ans, target);
        return ans;
    }
};
