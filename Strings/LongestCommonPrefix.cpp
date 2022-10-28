// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int index = 0;
        string a , b;
        
        if(strs.size() == 0)
            return "";
        
        sort(strs.begin(), strs.end());
        a = strs[0];
        b = strs[strs.size() - 1];
        
        for(int i = 0; i < a.length(); i++)
            if(a[i] == b[i])
                index++;
            else
                break;
                
        return a.substr(0, index);
    }
};
