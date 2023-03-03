// https://leetcode.com/problems/partition-equal-subset-sum/

/*
We can partition the array into two subsets that means, each element of original array will either belong to first subset or Second subset. Along with this we will need to track the sum of both of these two subsets and whenever we have allocated all elements of the vector in either of these two subsets, we will just compare the individual sum of both subsets. If they are equal, such a partition is possible.
Note: We just want two parition with equal subset sum meaning, each element of original array must be a part of either of two subsets. There is no bound on the size of the individual subsets. Just the N(subset1) + N(subset2) == N

TC - O(2 ^ n)
SC - O(n)
*/

class Solution {
public:
    bool helper(vector<int>& nums, int index, int sum1, int sum2)
    {
        if(index >= nums.size())
            return sum1 == sum2;

        bool PickInSubset1 = helper(nums, index + 1, sum1 + nums[index], sum2);
        bool PickInSubset2 = helper(nums, index + 1, sum1, sum2 + nums[index]);

        return PickInSubset1 || PickInSubset2;
    }
    bool canPartition(vector<int>& nums) 
    {
        int sum1 = 0, sum2 = 0, index = 0;
        return helper(nums, index, sum1, sum2);
    }
};

/* 
Optimization - We can see that if the total sum of all elements in the array is odd, it is impossible to divide the array into two partitions such that sum of both results in the sum of the original array.
Therefore, we can caculate the total sum at first and if it is odd, directly return false.

This will improve best case TC but worst case time complexity will still remain same as brute force.

Observation 2: We want two partitions having equal sum and and their sum equal to total sum of array. This means that if total sum of array is S, sum of each subset will be S/2.
If we are able to find S and anothe subset with sum S/2, we don't need to care about finding the other corresponding subset with sum S/2 because it will always exist, if there is one subset with sum S/2 and S is even.

Therefore, this problem now converts to finding a subset with sum equal to target sum. 
TC - O(n * k) + O(n) (Extra O(n) space to find the total sum)
SC - O(k) + O(k)
*/

class Solution {
public:
    int subsetSumToK(vector<int>&nums, int target)
    {
        vector<bool> prev(target + 1, false), curr(target + 1, false);

        prev[0] = true;

        if(nums[0] <= target)
            prev[nums[0]] = true;

        for(int i = 1; i < nums.size(); i++)
        {
            curr[0] = true;
            for(int j = 1; j <= target; j++)
            {
                bool notpick = prev[j];
                bool pick = false;
                if(nums[i] <= j)
                    pick = prev[j - nums[i]];

                curr[j] = pick || notpick;
            }

            prev = curr;
        }

        return prev[target];
    }
  
    bool canPartition(vector<int>& nums) 
    {
        int totalsum = 0, target;
        totalsum = accumulate(nums.begin(), nums.end(), totalsum);
        target = totalsum / 2;

        if(totalsum & 1)    //Odd number will have their last bit as 1 always. 1 & 1 will equal to 1 which is non-zero, therefore condition will be true.
            return false;

        return subsetSumToK(nums, target);
    }
};
