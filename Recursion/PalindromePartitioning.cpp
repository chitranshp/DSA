// https://leetcode.com/problems/palindrome-partitioning/


class Solution {
public:
    bool isPalindrome(string &s, int beg, int end)
    {
        while(beg < end)
        {
            if(s[beg++] != s[end--])
                return false;
        }

        return true;
    }

    void generateSubstring(string &str, vector<vector<string>> &res, vector<string> &temp, int index)
    {
        if(index == str.size())
        {
            res.push_back(temp);
            return;
        }

        for(int i = index; i < str.size(); i++)
        {
            if(isPalindrome(str, index, i))
            {
                temp.push_back(str.substr(index, i - index + 1));
                generateSubstring(str, res, temp, i + 1);
                temp.pop_back();
            }
        }      
    }

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> temp;
        generateSubstring(s, res, temp, 0);
        return res;
    }
};
