//leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        vector<string> s;
        string res;
        
        for(int i = 0; i < nums.size(); i++)
            s.push_back(to_string(nums[i]));
            
        sort(s.begin(), s.end(), [](string &s1, string &s2){ return s1 + s2 > s2 + s1; });
            
        for(int i = 0; i < nums.size(); i++)
            res = res + s[i];
        
        while(res[0] == '0' && res.length() > 1)
            res.erase(0, 1);
            
        
        return res;
            
    }
};
