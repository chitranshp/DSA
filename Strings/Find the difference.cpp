// https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int freq[26] = {0}, sum = 0, i;
        
        for(i = 0; i < s.length(); i++)
            sum += t[i] - s[i];
        
        return sum + t[i];
    }
};
