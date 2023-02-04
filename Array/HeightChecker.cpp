// https://leetcode.com/problems/height-checker/submissions/891470019/

class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        int val = 0;
        vector<int> h(heights);
        sort(heights.begin(), heights.end());
        for(int i = 0; i < heights.size(); i++)
           val += heights[i] != h[i];

        return val; 
    }
};
