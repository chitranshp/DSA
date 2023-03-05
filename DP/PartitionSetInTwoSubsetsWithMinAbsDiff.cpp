// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
// This is only for when array values are positive.

/*
Brute Force
TC - O(2 ^ n)
SC - O(n)
*/
void helper(vector<int>& arr, int csum1, int csum2, int globalmin, int index)
{
  if(index == -1)
  {
    globalmin = min(globalmin, abs(csum1 - csum2));
    return;
  }
  
  // Assign arr[index] to first subset
  helper(arr, csum1 + arr[index], csum2, globalmin, index + 1);
  
  // Assign arr[index] to second subset
  helper(arr, csum1, csum2 + arr[index], globalmin, index + 1);
  return;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int index = n - 1, sum1 = 0, sum2 = 0, globalmin = INT_MAX;
	helper(arr, sum1, sum2, globalmin, index);
	return globalmin;
}


/*
We don't need to track each of these 2 subarrays for the partition. We can find the totalsum for the whole array which will be constant throught the problem and then find all the possible combinations for subarray1. And for subarray2, we just subtract the sum of subarray1 from totalsum.
Sum of subarray1 will can be between 0 and totalsum(both inclusive). So, we just find which all values between 0 and totalsum are possible. And for all those values which are possible as sum of subarray sum, we find the corresponding sum of subarray2 and therefore calculate the min absolute difference.
For finding these values, we will have to iterate and check possible values for subarray1 sum in last row of dp i.e. dp[n - 1][k] which represents whether from index 0 to index 'n - 1' a target sum of 'k' can be obtained or not where 0<= k <= totalsum.

Tabulation - The benefit of Tabulation approach is that this will find all the inbetween values(0 - totalsum) which is possible for sum of subarray1,  if we just find the value for dp[n - 1][totalsum].
TC - O(N*totSum) +O(N) +O(N) (There are two nested loops that account for O(N*totSum), at starting we are running a for loop to calculate totSum, and at last a for loop to traverse the last row.)
SC - O(N*totSum)
*/
void helper(vector<int>& arr, int target, vector<vector<bool>> &dp)
{
	for(int i = 0; i < arr.size(); i++)
	{
		dp[i][0] = true;
	}

	if(arr[0] <= target)
		dp[0][arr[0]] = true;

	for(int i = 1; i < arr.size(); i++)
	{
          for (int j = 1; j <= target; j++) 
		  {
            bool notpick = dp[i - 1][j];
            bool pick = false;
            if (arr[i] <= j)
              pick = dp[i - 1][j - arr[i]];

            dp[i][j] = pick || notpick;
          }
	}

	return;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalsum = 0;
	totalsum = accumulate(arr.begin(), arr.end(), totalsum);

	vector<vector<bool>> dp(n, vector<bool> (totalsum + 1, 0));

	helper(arr, totalsum, dp);

	int mindiff = 1e8;
	for(int j = 0; j <= totalsum; j++)
		if(dp[n - 1][j] == true)  //If that subset sum exists/achievable only then.
			mindiff = min(mindiff, abs(totalsum - j - j));

	return mindiff;
}

/*
Space Optimization - We only need the final row for calculating our final answer. And for finding target we need current and previous rows.
TC - O(N*totSum) +O(N) +O(N) (There are two nested loops that account for O(N*totSum), at starting we are running a for loop to calculate totSum, and at last a for loop to traverse the last row.)
SC - O(totalsum)
*/

void helper(vector<int>& arr, int target, vector<bool>& prev)
{
	vector<bool> curr (prev);
	prev[0] = true;

	if(arr[0] <= target)
		prev[arr[0]] = true;

	for(int i = 1; i < arr.size(); i++)
	{
		  curr[0] = true;
          for (int j = 1; j <= target; j++) 
		  {
            bool notpick = prev[j];
            bool pick = false;
            if (arr[i] <= j)
              pick = prev[j - arr[i]];

            curr[j] = pick || notpick;
          }

		  prev = curr;
	}

	return;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalsum = 0;
	totalsum = accumulate(arr.begin(), arr.end(), totalsum);

	vector<vector<bool>> dp(n, vector<bool> (totalsum + 1, 0));
	vector<bool> prev(totalsum + 1, false);

	helper(arr, totalsum, prev);

	int mindiff = 1e8;
	for(int j = 0; j <= totalsum; j++)
		if(prev[j] == true)
			mindiff = min(mindiff, abs(totalsum - j - j));

	return mindiff;
}
