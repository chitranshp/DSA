// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    void funhelper(vector<vector<int>> &ans, vector<int> &temp, int k, int n, int index)
    {
        if(temp.size() == k)
        {
            if(n == 0)
                ans.push_back(temp);
            return;
        }

        if(index > 9 || n < 0)
            return;

        temp.push_back(index);
        funhelper(ans, temp, k, n - index, index + 1);
        temp.pop_back();
        funhelper(ans, temp, k, n, index + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        funhelper(ans, temp, k, n, 1);
        return ans;
    }
};
