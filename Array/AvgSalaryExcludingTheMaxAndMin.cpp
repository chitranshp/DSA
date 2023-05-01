// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

/*
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    double average(vector<int>& salary) 
    {
        double val = 0;
        int minval = INT_MAX, maxval = INT_MIN;

        for(int i = 0; i < salary.size(); i++)
        {
            val += salary[i];
            minval = min(minval, salary[i]);
            maxval = max(maxval, salary[i]);
        }

        return (val - minval - maxval) / (salary.size() - 2);
    }
};