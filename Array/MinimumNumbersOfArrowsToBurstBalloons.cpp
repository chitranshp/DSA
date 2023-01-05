// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int arrow = 1, minval = points[0][1];       //For first arrow
        sort(points.begin(), points.end());

        for(auto &x: points)
        {
            if(x[0] > minval)
            {
                arrow++;
                minval = x[1];
            }
            else
            {
                minval = min(minval, x[1]);
            }
        }
        return arrow;
    }
};
