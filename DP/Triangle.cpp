// https://leetcode.com/problems/triangle/

/* Recursion 
In first row there is 1 column, 2 in 2nd, 3 in 3rd and i in ith row.
So in total there will be 1+2+3+....+n states = O(n^2 and at each state we will have two options.
Therefore, t\otal TC = O(2 ^ ( n ^ 2))
SC = O(N)

We are not doing row n to row 0 recursion(tail) because if we go from last row to first row we will have multiple starting points a[m - 1][n - 1] to arr[m - 1][0].
And we will have to calcuate answer for all the paths and then take the minimum. Therefore, there will be multiple recurrences. 
But if we go from first row to last row, we will have only 1 starting points and we just need to find the minimum through that point.
*/

class Solution {
public:
    int helper(vector<vector<int>> &triangle, int r, int c)
    {
        if(r == triangle.size() - 1)
            return triangle[r][c];

        /*
        //This case is not necessary because for given r and c, c and c + 1 will always be withing array range(As size of each row is 1 more than it's previous one). And for row we have previous if condition which won't allow r to grow out of array bound.
        if(r >= triangle.size() || c >= triangle[r].size())   //Size of each row is different
            return INT_MAX;
        */

        int down = triangle[r][c] + helper(triangle, r + 1, c);
        int diagonal = triangle[r][c] + helper(triangle, r + 1, c + 1);
        return min(down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        return helper(triangle, 0, 0);    
    }
};

/* 
Memoization
Time complexity will be equal to number of states ie O(n * (n + 1)) / 2 or we can say that O(n ^ 2)
SC will be O(n ^ 2) + O(n) [Stack space]
*/

class Solution {
public:
    int helper(vector<vector<int>> &triangle, int r, int c, vector<vector<int>> &dp)
    {
        if(r == triangle.size() - 1)
            return triangle[r][c];

        if(dp[r][c] != -1)
            return dp[r][c];

        int down = triangle[r][c] + helper(triangle, r + 1, c, dp);
        int diagonal = triangle[r][c] + helper(triangle, r + 1, c + 1, dp);
        return dp[r][c] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        return helper(triangle, 0, 0, dp);    
    }
};

/*
Tabulation
Time complexity will be equal to number of states ie O(n * (n + 1)) / 2 or we can say that O(n ^ 2)
SC will be O(n ^ 2)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size(), n = triangle[m - 1].size();
        vector<vector<int>> dp(triangle.size() , vector<int> (triangle.size(), 0));

        /* Using our memoization base case here also */
        for(int j = 0; j < n; j++)
            dp[m - 1][j] = triangle[m - 1][j];
        //Since our base case is for last row, we will have to fill our table from last to first row
        for(int i = m - 2; i >= 0; i--)     //As we already have done for row m - 1 in base case.
        {
            //For 0th row -> 0 column, 1st row -> 0, 1 column
            for(int j = i; j >= 0; j--)
            {
                //Reused same code as in memoization 
                int up = (long) triangle[i][j] + dp[i + 1][j];
                int diagonal = (long)triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(up, diagonal);
            }
        }

        //If we calculated from 1st row to last one, we again would have to find the minimum among all columns in last row and return it.
        return dp[0][0];    
    }
};

/*
Space Optimization - We only need two rows at a time, which are the current one on which we are workinga and immidiate next one
SC - O(N) + O(N)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size(), n = triangle[m - 1].size();
        vector<int> front(n, 0), curr(n, 0);

        /* Using our memoization base case here also */
        for(int j = 0; j < n; j++)
            curr[j] = triangle[m - 1][j];
        //Since our base case is for last row, we will have to fill our table from last to first row
        for(int i = m - 2; i >= 0; i--)     //As we already have done for row m - 1 in base case.
        {
            //For 0th row -> 0 column, 1st row -> 0, 1 column
            for(int j = i; j >= 0; j--)
            {
                //Reused same code as in memoization 
                int up = (long) triangle[i][j] + front[j];
                int diagonal = (long)triangle[i][j] + front[j + 1];
                curr[j] = min(up, diagonal);
            }

            front = curr;
        }

        //If we calculated from 1st row to last one, we again would have to find the minimum among all columns in last row and return it.
        return curr[0];    
    }
};

/*
Further Space Optimization can also be done by using same input triangle to store the values instead of another DS
*/


