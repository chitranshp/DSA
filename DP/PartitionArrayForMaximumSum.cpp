// https://leetcode.com/problems/partition-array-for-maximum-sum/

/*
TC - Exponential
SC - O(1)
*/

class Solution {
public:
    int helper(vector<int> &arr, int index, int k)
    {
        int n = arr.size();
        if(index >= n)
            return 0;

        int maxsum = INT_MIN, len = 0, maxele = INT_MIN;

        // Here it is given that length of a partition can be atmost 'k'. For each 'i', we will check max sum that can be obtained, if a partition is made at that 'i'.
        // Note: i < min(INDEX + k, n), if we keep it as i < min(i + k, n) it will essentially become i < n as i will be always less than i + k. Also for first element we can only partition at index 0, 1 & 2.
        for(int i = index; i < min(index + k, n); i++)
        {
            // To keep track of length of partition and to be used in finding the sum.
            len++;
            // Records maxele of this partition relative to arr[index] to arr[i]
            maxele = max(arr[i], maxele);

            // It is given that after partitioning each subarray has values changed with the max value of that subarray. Therefore, we are multiplying max_element of the paritition with length of partition which gives the sum without the need of replacing/modifying the array values.
            int currsum = len * maxele + helper(arr, i + 1, k);   // After this we will recursively solve for the subsequent partitions.
            maxsum = max(maxsum, currsum);
        }

        return maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int n = arr.size();
        return helper(arr, 0, k);
    }
};

/*
Memoization - Here , dp[i] represents the maximum sum that can be obtained from index 'i' till last index.
TC - O(n * k)
SC - O(n) + O(n)
*/

class Solution {
public:
    int helper(vector<int> &arr, int index, int k, vector<int> &dp)
    {
        int n = arr.size();
        if(index >= n)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];

        int maxsum = INT_MIN, len = 0, maxele = INT_MIN;

        // Here we will check through all partitions of length atmost k. For each 'i', we will check max sum that can be obtained, if a partition is made at that 'i'.
        for(int i = index; i < min(index + k, n); i++)
        {
            // To keep track of length of partition and to be used in finding the sum.
            len++;
            // Records maxele of this partition relative to arr[index] to arr[i]
            maxele = max(arr[i], maxele);

            // It is given that after partitioning each subarray has values changed with the max value of that subarray. Therefore, we are multiplying max_element of the paritition with length of partition which gives the sum without the need of replacing/modifying the array values.
            int currsum = len * maxele + helper(arr, i + 1, k, dp);   // After this we will recursively solve for the subsequent partitions.
            maxsum = max(maxsum, currsum);
        }

        return dp[index] = maxsum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return helper(arr, 0, k, dp);
    }
};

/*
Tabulation
TC - O(n * k)
SC - O(n)
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);       //n + 1 to account for the base case

        for(int index = n - 1; index >= 0; index--)
        {
            int maxsum = INT_MIN, len = 0, maxele = INT_MIN;
            for(int i = index; i < min(index + k, n); i++)
            {
                len++;
                maxele = max(arr[i], maxele);

                int currsum = len * maxele + dp[i + 1]; 
                maxsum = max(maxsum, currsum);
            }

            dp[index] = maxsum;
        }
        
        return dp[0];
    }
};