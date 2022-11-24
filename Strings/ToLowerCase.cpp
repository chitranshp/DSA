// https://leetcode.com/problems/to-lower-case/description/

//O(n)
class Solution {
public:
    string toLowerCase(string s) 
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 32;
        }

        return s;
    }
};
