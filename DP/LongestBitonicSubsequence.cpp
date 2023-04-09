// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

/*
Longets bitonic subsequence can be any one of following:
1. Increasing subsequence
2. Decreasing subsequence  (We can think of it as increasing subsequence from end)
3. Strictly increasing then decreasing

For given arr - {1, 11, 2, 10, 4, 5, 2, 1}  Longest bitonic subsequence will be {1, 2, 10, 4, 2, 1} having length 7.

We can think of it as combination of two subsequences Longest increasing subsequence FROM 0 TILL INDEX 3
and longest increasing subsequence (from back) FROM INDEX 3 TILL END OF ARRAY. 
Index 3 is counted twice(in both subsequences), so we will subtract 1 from the length to make up for it.
i.e.    dp1[3] + dp2[3] - 1

So, to solve this we can create two dp vectors dp1 and dp2
dp1[I] -> To track longest increasing subsequence form 0 till index 'i'.
dp2 -> To track longest increasing subsequence (from back) from index 'i' till index 'n - 1'.

Length of longest bitonix subsequence will be 
		for(int i = 0; i < n; i++)
	        maxi = max(maxi, dp1[i] + dp2[i] - 1);

TC - O(n ^ 2)
SC - O(n)
*/

class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    int maxi = 0;
	    vector<int> dp1(n, 1), dp2(n, 1);
	    
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < i; j++)
	        {
	            if(nums[i] > nums[j] && dp1[i] < dp1[j] + 1)
	                dp1[i] = dp1[j] + 1;
	        }

			//maxi = max(maxi, dp1[i] + dp2[i] - 1);
	    }
	    
	    for(int i = n - 1; i >= 0; i--)
	    {
	        for(int j = n - 1; j > i; j--)
	        {
	            if(nums[i] > nums[j] && dp2[i] < dp2[j] + 1)
	                dp2[i] = dp2[j] + 1;
	        }

			//maxi = max(maxi, dp1[i] + dp2[i] - 1);
	    }
	    
		//Can be removed if we calculate maxi inside both previous loops
	    for(int i = 0; i < n; i++)
	        maxi = max(maxi, dp1[i] + dp2[i] - 1);
	        
	    return maxi;
	    
	}
};