// https://leetcode.com/problems/combinations/

class Solution {
public:
    void helperfun(int n, int k, int index, vector<vector<int>> &res, vector<int> &chosen)
    {
        if(chosen.size() == k)    
        {
            res.push_back(chosen);
            return;
        }
        
        for(int i = index; i <= n; i++)
        {
            chosen.push_back(i);
            helperfun(n, k, i + 1, res, chosen);
            chosen.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        vector<int> chosen;
        helperfun(n, k, 1, res, chosen);
        return res;
    }
};
