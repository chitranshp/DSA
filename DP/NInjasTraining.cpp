// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
// https://practice.geeksforgeeks.org/problems/geeks-training/1

/* 
Recursion + Backtracking 
Here as per question number of activity is fixed as 3. Only number of days(n) will be changing
TC - o(3 ^ n) SC - O(3) (There will be n day's and on each day we will explore all possible ways i.e try to perform all valid activity combinations where activity is fixed as 3. Therefore 3 * 3 * 3 * 3 ....n times)
*/

class Solution {
  public:
    void helper(vector<vector<int>>& points, int day, int lastactivity, int currpoints, int& maxpoints)
    {
        if(day <= -1)
        {
            globalsum = max(currpoints, globalsum);
            return;
        }
            
        for(int activity = 0; activity < points[0].size(); activity++)
        {
            if(activity != lastactivity)
            {
                currpoints += points[day][activity];
                helper(points, day - 1, r, activity, currpoints, maxpoints);
                currpoints -= points[day][activity];
            }
        }
    }
    int maximumPoints(vector<vector<int>>& points, int n) 
    {
        int sum = 0, globalsum = INT_MIN;
        helper(points, n - 1, -1, sum, globalsum);    //lastactivity as -1 indicates any valid activity can be taken for present day.
        return globalsum;
    }
};
