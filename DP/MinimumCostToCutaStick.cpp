// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

/*
With Plain recursion 
TC - O(n * n * n)   O(n ^ 2) to cover all the states and O(n) for the loop.
SC - O(n)

With Memoization(Recursion + DP)
TC - O(n ^ 3)
SC - O(n ^ 2) + O(n)
*/

class Solution {
public:
    int helper(vector<int>& cuts, int i, int j, vector<vector<int>> &dp) 
    {
        if(i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mincost = INT_MAX;
        for(int index = i; index <= j; index++)
        {
            //For cuts[1 - 1] = cuts[0] = 0 and cuts[cuts.size() - 2 + 1] = n, On subtracting they give n - 0 = n which is the length of stick.
            // For each value of i and j, cuts[j + 1] - cuts[i - 1] will give the length of stick.
            // We will make a cut at length 'index' and add the length of whole stick and then add the cost for newly created 2 sticks.
            // More cuts for newly created sticks can be performed at [i ... index - 1] and [index + 1 ..... j]
            // For 'index' cut has already been accounted for and no further new cuts can be performed at the same length.
            // i - 1 will give the index of starting point of left stick and j + 1(index - 1 + 1 = index) will give the ending of left stick.
            int val = cuts[j + 1] - cuts[i - 1] + helper(cuts, i, index - 1, dp) + helper(cuts, index + 1, j, dp);
            mincost = min(val, mincost);
        }

        return dp[i][j] = mincost;
    }

    int minCost(int n, vector<int>& cuts) 
    {
        int cutsLength = cuts.size();
        vector<vector<int>> dp(cuts.size() + 2, vector<int> (cuts.size() + 2, -1));
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        //Without sorting, the cuts cannot be solved independently. With sorting, we are guarranted that whatever point we are making the cut, the information on the markings of the left portion will always be present on the left side of the CUTS array partition. Similarly on the right side.
        sort(cuts.begin(), cuts.end());

        // i = 1 is the index for first(smallest) valid cut and j = cuts.size() - 2 is the index for last(largest) valid cut.
        // cuts[0] and element at cuts.size() - 1 are placeholders for ease of calculation.
        return helper(cuts, 1, cuts.size() - 2, dp);    //Here we are passing initial size of the cuts for index j.
    }
};

/*
Tabulation
TC - O(n ^ 3)
SC - O(n ^ 2)
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) 
    {
        vector<vector<int>> dp(cuts.size() + 2, vector<int> (cuts.size() + 2, 0));
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        for(int i = cuts.size() - 2; i >= 1; i--)
        {
            for(int j = 1; j <= cuts.size() - 2; j++)   //Another optimization can be made with initializing j with i instead of 1 as for all i > j, we have already handled it separately as part of vector initialization
            {
                if(i > j)
                    continue;       //dp[i][j] = 0 covered in initialization
                    
                int mincost = 1e8;
                for(int index = i; index <= j; index++)
                {
                    int val = cuts[j + 1] - cuts[i - 1] + dp[i][index - 1] + dp[index + 1][j];
                    mincost = min(val, mincost);
                }

                dp[i][j] = mincost;
            }
        }

        return dp[1][cuts.size() - 2];
    }
};
