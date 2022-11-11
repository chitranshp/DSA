// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void helperfun(vector<vector<int>> &res, vector<int> & candidates, int target, int index, vector<int> temp)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }

        if(target < 0)
            return;

        for(int i = index; i < candidates.size(); i++)
        {
            //i > index, to ensure duplicate combinations are avoided.
            if(i > index && candidates[i] == candidates[i - 1])
                continue;
            

            temp.push_back(candidates[i]);
            //i + 1 here
            helperfun(res, candidates, target - candidates[i], i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        // Sorting the input 
        sort(candidates.begin(), candidates.end());
        helperfun(res, candidates, target, 0, temp);
        return res;
    }
};
