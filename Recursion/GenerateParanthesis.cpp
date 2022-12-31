// https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
    void helper(int left, int right, string& curr, vector<string>& res)
    {
        if(left + right == 0)
        {
            res.push_back(curr);
            return;
        }

        if(left > 0)
        {
            curr += "(";
            helper(left - 1, right, curr, res);
            curr.pop_back();
        }
        
        if(right > left)
        {
            curr += ")";
            helper(left, right - 1, curr, res);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
       int left = n, right = n;
       vector<string> res;
       string str = "";

       helper(left, right, str, res);
       return res; 
    }  
};
