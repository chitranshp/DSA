// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) 
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        
        int before2step = 1;        //When there is only 1 step
        int before1step = 2;        //When there are two steps.
        int totalways = before2step + before1step;      //When there are three steps
        
        for(int i = 2; i < n; i++)
        {
            totalways = before2step + before1step;
            before2step = before1step;
            before1step = totalways;
        }
        return totalways;
    }
};
