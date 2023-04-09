// https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/

/*
Approach 1 - DP
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int n = nums.size(), maxi = 0;
        vector<int> dp(n, 1);   //Default initialization with 1. 

        for(int i = 0; i < n; i++)
        {
            if(i == 0 || nums[i - 1] < nums[i])
                dp[i] = 1 + dp[i - 1];
            /*
            else
                dp[i] = 1;
            */

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};

/*
Approach 2 - Sliding window - If condition matches, keep increasing the window size by 1. Else, reset it to 1.
Keep track of largest window size reached throughout the loop and return it as answer.
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int n = nums.size(), cnt = 0, maxi = 1;      //Minimum size of array is 1.
        
        for(int i = 0; i < n; i++)
        {
            if(i == 0 || nums[i - 1] < nums[i])
                cnt++;    //Increase
            else
                cnt = 1;  //Reset

            maxi = max(cnt, maxi);
        }

        return maxi;
    }
};