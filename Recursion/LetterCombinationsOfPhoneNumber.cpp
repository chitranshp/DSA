// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:

    void solve(vector<string> &res, vector<string> &keypad, string &digits, int index, string &s)
    {
        if(index >= digits.size())
        {
            res.push_back(s);
            return;
        }
        
        //As digits[index] is a char and keypad uses an integer for indexing.
        for(char& ch: keypad[digits[index] - '0'])
        {
            s += ch;
            solve(res, keypad, digits, index + 1, s);
            s.pop_back();
        }      
    }


    vector<string> letterCombinations(string digits) 
    {
        if(!digits.size())
            return {};
            
        vector<string> keypad {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;
        string s = "";
        solve(res, keypad, digits, 0, s);


        return res;
    }
};
