// https://leetcode.com/problems/target-sum/

/*
Approach 1: Recursion
TC - O(2 ^ N)
SC - O(N)
*/
class Solution {
public:
    int helper(vector<int>& nums, int target, int index)
    {
        if(index == -1)
        {
            /*
            int ans = 0;
            if(target - nums[0] == 0)
                ans++;
            if(target + nums[0] == 0)
                ans++;

            return ans;
            */
            return target == 0;
        }

        int a = helper(nums, target + nums[index], index - 1);
        int b = 0;
        //Since, negative intermediate sum can also be generated which will lead to target. We are not checking whether target - nums[index] >= 0.
        b = helper(nums, target - nums[index], index - 1);

        return a + b;
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return helper(nums, target, nums.size() - 1);
    }
};

// Memoization for approach 1
/*
TC - O(N * S) where S can range from [-sum(nums), + sum(nums)] in worst case
SC - O(N * S) + O(N)
*/
class Solution {
public:
    int helper(vector<int>& nums, int target, int index, vector<unordered_map<int, int>> &dp)
    {
        if(index == -1)
        {
            /*
            int ans = 0;
            if(target - nums[0] == 0)
                ans++;
            if(target + nums[0] == 0)
                ans++;

            return ans;
            */
            return target == 0;
        }

        auto it = dp[index].find(target);
        if(it != dp[index].end())
            return it->second;

        int a = helper(nums, target + nums[index], index - 1, dp);
        int b = helper(nums, target - nums[index], index - 1, dp);

        return dp[index][target] = a + b;
        //Inside dp vector, it will go to index pointed by variable 'index'. In that unordered set, it will insert a key 'target' having value 'a + b'.
        //Here target means, all the total sum we will be getting throughout adding or subtracting the elements. It could be anywhere between ()-totalsum,+totalsum).
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        vector<unordered_map<int, int>> dp(nums.size());
        return helper(nums, target, nums.size() - 1, dp);
    }
};

//Approach 2
/*
If we look closely at this example
                                        [1,1,1,1,1] Target = 3

                                        -1 + 1 + 1 + 1 + 1 = 3      [1, 1, 1, 1] [1]
                                        +1 - 1 + 1 + 1 + 1 = 3      [1, 1, 1, 1] [1]
                                        +1 + 1 - 1 + 1 + 1 = 3      [1, 1, 1, 1] [1]
                                        +1 + 1 + 1 - 1 + 1 = 3      [1, 1, 1, 1] [1]
                                        +1 + 1 + 1 + 1 - 1 = 3      [1, 1, 1, 1] [1]

We can see that, instead of adding + and - signs over each element and tracking the end resultant for final result. We can just divide the original array into two partitions in such a way that difference of those 2 partitions should be our 'Target'.
NOTE: -1 - 2 - 3 = -(1 + 2 + 3)

Let N be the original array. And S1 and S2, be the two such partitions sum whereas S be the totalsum of N.
        S1 + S2 = S
        S1 = S - S2 -(i)

        And, S1 - S2 = target -(ii)

        Putting (i) in (ii), we get
        S - S2 - S2 = target
        S - target = 2 * S2
        (S - target) / 2 = S2 (S2 is sum of all elements in Partition2)

This means that, if we get any subset whose sum is equal to (S - target) / 2, that represents 1 unique way to get our target as per question.
Therefore this question is modified to “Count Number of subsets with sum (totSum – target)/2 ”. This is exactly what we had discussed in problem Count Subsets with Sum K.

Edge Cases:
This will also be similar to the problem CountSubsetsWithSumK.cpp

    Constraint: 0 <= nums[i] <= 1000
    Therefore, Sum of elements in both partition cannot be negative.

    i. S - target must be greater than or equal to 0
    ii. (S - target) must be even - S2 i.e. sum of all elements(integers) in partition 2 cannot be fraction. 
        Therefore, (S - target) should be an even number. Then when it will be divided by 2, it will return an integer not a fraction.

TC - O(N * S) + O(N) (FOR TOTALSUM)
SC - O(N * S) + O(N)
*/

class Solution {
public:
    int helper(vector<int>& nums, int target, int index, vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            if(target == 0  && nums[0] == 0)
                return 2;
            else if(target == 0 || target == nums[0])
                return 1;

            return 0;
        }

        if(dp[index][target] != -1)
            return dp[index][target];

        int notpick = helper(nums, target, index - 1, dp);
        int pick = 0;
        if(nums[index] <= target)
            pick = helper(nums, target - nums[index], index - 1, dp);

        return dp[index][target] = pick + notpick;
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int totalsum = 0;
        totalsum = accumulate(nums.begin(), nums.end(), totalsum);

        if(totalsum - target < 0)
            return 0;
        else if((totalsum -target) % 2 != 0)
            return 0;
        else if(totalsum < target)      //If target = 1000 and totalsum(max possible value) is 100
            return 0;

        int s2 = (totalsum - target) / 2;
        //Add + 1 in size for the case when array is made up of all zeroes and s2 is 0.     [0,0,0,0,1] target = 1
        vector<vector<int>> dp(nums.size(), vector<int> (s2 + 1, -1));

        return helper(nums, s2, nums.size() - 1, dp);
    }
};

/* 
Memoization
TC - O(N) + O(N * S)
SC - O(N * S)
*/
class Solution {
public:
    int findWays(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
            
        if(arr[0] == 0)
            dp[0][0] = 2;
        else   
            dp[0][0] = 1;
        
        if(arr[0] != 0 && arr[0] <= sum)
            dp[0][arr[0]] = 1;
                
        for(int i = 1; i < n; i++)
        {
            /* Important */
            //Here, j is running from 0 to sum (BOTH INCLUSIVE). This is to handle the cases where 0 is present at any index other than 0.
            /*
            Dry run this test case
            10 31
            9 7 0 3 9 8 6 5 7 6
            */
            for(int j = 0; j <= sum; j++)
            {
                int notpick = dp[i - 1][j];
                int pick = 0;
                if(arr[i] <= j)
                    pick = dp[i - 1][j - arr[i]];
                        
                dp[i][j] = (pick + notpick);
            }
        }
    
        return dp[n - 1][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int totalsum = 0;
        totalsum = accumulate(nums.begin(), nums.end(), totalsum);

        if(totalsum - target < 0 || (totalsum - target) % 2 == 1)
            return 0;
        int s2 = (totalsum - target) / 2;
        return findWays(nums, s2); 
    }
};

/* 
SpaceOptmization
SC - O(S) + O(S)
*/

class Solution {
public:
    int findWays(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
            
        if(arr[0] == 0)
            prev[0] = 2;
        else   
            prev[0] = 1;
        
        if(arr[0] != 0 && arr[0] <= sum)
            prev[arr[0]] = 1;
                
        for(int i = 1; i < n; i++)
        {
            /* Important */
            //Here, j is running from 0 to sum (BOTH INCLUSIVE). This is to handle the cases where 0 is present at any index other than 0.
            /*
            Dry run this test case
            10 31
            9 7 0 3 9 8 6 5 7 6
            */
            for(int j = 0; j <= sum; j++)
            {
                int notpick = prev[j];
                int pick = 0;
                if(arr[i] <= j)
                    pick = prev[j - arr[i]];
                        
                curr[j] = (pick + notpick);
            }

            prev = curr;
        }
    
        return prev[sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int totalsum = 0;
        totalsum = accumulate(nums.begin(), nums.end(), totalsum);

        if(totalsum - target < 0 || (totalsum - target) % 2 == 1)
            return 0;
        int s2 = (totalsum - target) / 2;
        return findWays(nums, s2); 
    }
};

/*
Further Space optimization - We can see that for each cell we are accessing directly above cell and one cell from it's left in current row.
Here, 'j - nums[i]' will always be a cell towards left of current cell.
So, if we start filling table from right to left, we can use single row data structure and just overwrite it's values.

SC - O(S)
*/

class Solution {
public:
    int findWays(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<int> prev(sum + 1, 0);
            
        if(arr[0] == 0)
            prev[0] = 2;
        else   
            prev[0] = 1;
        
        if(arr[0] != 0 && arr[0] <= sum)
            prev[arr[0]] = 1;
                
        for(int i = 1; i < n; i++)
        {
            /* Important */
            //Here, j is running from 0 to sum (BOTH INCLUSIVE). This is to handle the cases where 0 is present at any index other than 0.
            /*
            Dry run this test case
            10 31
            9 7 0 3 9 8 6 5 7 6
            */
            for(int j = sum; j >= 0; j--)
            {
                int notpick = prev[j];
                int pick = 0;
                if(arr[i] <= j)
                    pick = prev[j - arr[i]];
                        
                prev[j] = (pick + notpick);
            }
        }
    
        return prev[sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int totalsum = 0;
        totalsum = accumulate(nums.begin(), nums.end(), totalsum);

        if(totalsum - target < 0 || (totalsum - target) % 2 == 1)
            return 0;
        int s2 = (totalsum - target) / 2;
        return findWays(nums, s2); 
    }
};