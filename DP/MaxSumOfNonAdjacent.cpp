// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
// https://leetcode.com/problems/house-robber/description/

//User function template for C++

/* 
Here, the question is not asking for max sum of alternating elements. It is asking for non-adjacent elements. For 3, 2, 7, 10 the max sum of non-adjacent element will be 13(3 + 10).
At each step, we have two options:
1. Pick that element and include it in the sum. And after that ignore the next element.
2. Don't pick the current element and jump to the next element while including it in the sum.

Base case:
 if(index < 0)
  return 0; 
    
    or
 if(index == 0)                     If there is only 1 element in the array, the maximum sum will be arr[0].
  return arr[index];
  
 if(index < 0)
  return 0;
Time complexity will be O(2 ^ n) and space complexity will be O(n) for recursion stack (Since, f(index - 1) will execute n times)
*/
class Solution
{
public:	
	int helper(int *arr, int index)
	{
      if(index < 0)
          return 0;
    
	    if(index == 0)
	        return arr[index];
	    
      int pick = arr[index] + helper(arr, index - 2);
      int notpick = helper(arr, index - 1);
    
      return max(pick, notpick);
      //return max(arr[index] + helper(arr, index - 2), helper(arr, index - 1));
	}
  
	int findMaxSum(int *arr, int n)
    {
	    return helper(arr, n - 1, dp);
	}
};


/*
Memoization - TopDown DP 
If we draw the recursion tree, we can see that there are overlapping subproblems. Therefore applying DP to reduce the time complexity.
TC - O(n) approx. and SC - O(n) + O(n) = O(n) approx.
For 3 2  7 10
dp  3 3 10 13
*/

//User function template for C++
class Solution
{
public:	
	int helper(int *arr, int index, vector<int>& dp)
	{
	   if(index < 0)
	    return 0;
    
     if(index == 0)
      return arr[index];
	        
	   if(dp[index] != -1)
	    return dp[index];
	        
	   return dp[index] = max(helper(arr, index - 2, dp) + arr[index], helper(arr, index - 1, dp));
	}
  
	int findMaxSum(int *arr, int n) 
  {
	  vector<int> dp(n + 1, -1);
	  return helper(arr, n - 1, dp);
	}
};

/*
Tabulation - Bottom Up DP
TC - O(N) and SC - O(N)
*/

class Solution
{
public:	
  int findMaxSum(int *arr, int n) 
  {
	  vector<int> dp(n + 1, -1);
	  dp[0] = arr[0];       //Max sum of non-adjacent element UNTILL 0th index is arr[0].
    
    for(int i = 1; i < n; i++)
    {
      int pick = arr[i];
      if(i > 1)           // As when i = 1, dp[i - 2] will result in indexoutofbound error
        pick += dp[i - 2];
        
      int notpick = dp[i - 1];
        
      dp[i] = max(pick, notpick);
	  }
    
      return dp[n - 1];
  }
};

/*
Space Optimal Approach - We can observe that for any index i, we only need previous 2 values of max sum of non-adjacent elements. Rest all values are not needed and we can discard it.
TC - O(n) and SC - O(1)
*/

class Solution
{
public:	
  int findMaxSum(int *arr, int n) 
  {
	  int prev = arr[0], prev2, curri;

    for(int i = 1; i < n; i++)
    {
      int pick = arr[i];
      if(i > 1)           // As when i = 1, dp[i - 2] will result in indexoutofbound error
          pick += prev2;
        
      int notpick = prev;
        
      curri = max(pick, notpick);

		//Setting up values for next iteration.
		prev2 = prev;
		prev = curri;
	  }
    
  return prev;		//If we are returning curri instead of prev, we need to handle the case for which n = 1(where for loop won't be executed). We can declare initial value of curri as arr[0] to deal with that.
  }
};
