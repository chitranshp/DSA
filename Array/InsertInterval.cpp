// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int x = newInterval[0];
        int y = newInterval[1];
        int i = 0, n = intervals.size();
        vector<vector<int>> res;

        //Loop and push all intervals untill we find an overlapping interval.
        while(i < n && intervals[i][1] < newInterval[0])        //Entry condition
            res.push_back(intervals[i++]);
        
        /*
        If i is still < n, then this means then there is atleast 1 overalapping interval present and we are present at that interval.
        So, when interval is overlapping, we will create a new interval. For looping we use starting value of interval and loop untill start value of the interval becomes larger then end value of new interval.
        */
        while(i < n && intervals[i][0] <= newInterval[1])       //Entry condition
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i++][1], newInterval[1]);
        }

        //Push the new interval. This will execute regardless of previous loop and i's value.
        res.push_back(newInterval);
        
        //If there are still remaining values, push to vector.
        while(i < n)
            res.push_back(intervals[i++]);

        return res;
    }
};
