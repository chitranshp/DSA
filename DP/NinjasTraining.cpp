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
            maxpoints = max(currpoints, maxpoints);
            return;
        }
            
        for(int activity = 0; activity < points[0].size(); activity++)
        {
            if(activity != lastactivity)
            {
                currpoints += points[day][activity];
                helper(points, day - 1, activity, currpoints, maxpoints);
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

/* 
Approach 2: Using Plain Recursion
Simplified the problem as just f(day, lastactivity). At each step, for given day and lastactivity performed we will try all possible valid activities and return the activity which gives maximum possible points for that step with the given last activity.
                                                                    f(2, 3)   day = 2, last = 3(Which means 0, 1, 2 all will be valid for next step)
                      points[1][0]  +  f(1, 0)                  points[1][1]+  f(1, 1)            points[1][2]  f(1, 2)       Note: here f(1, 0) means on day 1 activity 0 is performed. Therefore on next call i.e. for day 0 activity 0 cannot be performed
                       f(0, 1)  f(0, 2)                          f(0, 0)   f(0, 2)       f(0, 0)   f(0, 1)
                         0         0                                 0         0             0         0                       
*/

class Solution {
  public:
    int helper(vector<vector<int>>& points, int day, int lastactivity)
    {
        if(day < 0)
            return 0;
        
        int maxpoints = INT_MIN;
        for(int activity = 0; activity < points[0].size(); activity++)
        {
            if(activity != lastactivity)
            {
                int currpoints = points[day][activity] + helper(points, day - 1, activity);
                maxpoints = max(maxpoints, currpoints);
            }
        }
        return maxpoints;
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) 
    {
        int sum = 0, globalsum = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(4, -1)) ;
            
        //lastactivity as 3 indicates any valid activity can be taken for present day.
        return helper(points, n - 1, 3);
    }
};

/*
Memoization - TopDown DP
TC - O(n * 4 * 3) SC - O(n) + O(n * 4)      
There are N*4 states and for every state, we are running a for loop iterating three times.
For each day there will be 4 states a 0,1,2,3 where 1 indicates task 1 was last performed and similarly task 3 indicates none of the tasks were performed on previous day.
And for each state we will run a for loop from 0 -> 2 ie 3 iterations.
*/

class Solution {
  public:
    int helper(vector<vector<int>>& points, int day, int lastactivity, vector<vector<int>>& dp)
    {
        if(day < 0)
            return 0;
        
        if(dp[day][lastactivity] != -1)
            return dp[day][lastactivity];
        
        int maxpoints = INT_MIN;
        for(int activity = 0; activity < points[0].size(); activity++)
        {
            if(activity != lastactivity)
            {
                int currpoints = points[day][activity] + helper(points, day - 1, activity, dp);
                maxpoints = max(maxpoints, currpoints);
            }
        }
        return dp[day][lastactivity] = maxpoints;
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) 
    {
        int sum = 0, globalsum = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(4, -1)) ;
            
        //lastactivity as 3 indicates any valid activity can be taken for present day.
        return helper(points, n - 1, 3, dp);
    }
};

/* 
Tabulation - BottomUp DP
TC - O((n * 4) * 3) SC - O(n * 4)

Hint: f(0, 0) means we are at day 0 and the last activity was 0th. Therefore, we can perform task 1 and task2 only and will be taking maximum of both.
*/
*/
int maximumPoints(vector<vector<int>>& points, int n) 
{
        int sum = 0, globalsum = INT_MIN;
        int ans = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(4, -1)) ;
            
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));  //3rd index will collect maximum of all points by all valid activity combinations till that day 
				
	for(day = 1; day < n; day++)
		for(last = 0; last < 4; last++)
		{
			dp[day][last] = 0;
        		for(int activity = 0; activity < points[0].size(); activity++)
        		{
            			if(activity != last)
            			{
                			int currpoints = points[day][activity] + dp[day - 1][activity];
                			dp[day][last] = max(dp[day][last], currpoints);
					//dp[day][last] = max(dp[day][last], points[day][activity] + dp[day - 1][activity]);
           			}
        		}
		}
		
        return dp[n - 1][4];
}

/*
Space optimization 
If we look closely at 
	dp[day][last] = max(dp[day][las], points[day][activity] + dp[day - 1][activity]) 
We are using only 2 rows of table dp at each step dp[day] and dp[day - 1]. We are using dp[day - 1] values to calculate the values for dp[day]. Therefore we don't need to store entire n * 4 table.
Instead, we will store just one vector of size 1 * 4 and use that to find values for current day. After this we will store the new values over the existing previous one. And will make the new one as prev for next iteration.
TC - O(n * 4 * 3) SC - O(4)
*/

class Solution {
  public:
    int helper(vector<vector<int>>& points, int day, int lastactivity, vector<vector<int>>& dp)
    {
        if(day < 0)
            return 0;
        
        if(dp[day][lastactivity] != -1)
            return dp[day][lastactivity];
        
        int maxpoints = INT_MIN;
        for(int activity = 0; activity < points[0].size(); activity++)
        {
            if(activity != lastactivity)
            {
                int currpoints = points[day][activity] + helper(points, day - 1, activity, dp);
                maxpoints = max(maxpoints, currpoints);
            }
        }
        
        return maxpoints;
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) 
    {
        vector<int> prev(4, 0);
            
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));  //3rd index will collect maximum of all points by all valid activity combinations till that day 
            
        for(int day = 1; day < n; day++)
        {
            vector<int> currdp(4, 0);       //To store the values for current day.
            for(int last = 0; last < 4; last++)
            {
                for(int activity = 0; activity < 3; activity++)
                {
                    if(activity != last)
                    {
                        currdp[last] = max(currdp[last], points[day][activity] + prev[activity]);
                    }
                }
            }
            prev = currdp; //Make the current values as prev for the next iteration by overwriting it.
        }
            
        return prev[3];
    }
};
