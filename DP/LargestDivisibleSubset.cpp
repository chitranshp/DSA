// https://leetcode.com/problems/largest-divisible-subset/

/*
Let given array be {7, 4, 1, 8, 16}
Let's sort it first. It will be {1, 4, 7, 8, 16}

Now, we know that if a % b = 0 and b % c = 0 then a % c also equals to 0.
ex.                  8 % 4 = 0 and 4 % 2 = 0 then 8 % 2 also 0.

So, instead of compairing each new element with all previous elements of our subarray, we will sort it and take elements and compare it with
previous element of subarray which is also the largest element so far but will be less than or equal to current element(As array is sorted)

Now, this problem becomes similar to largest increasing subsequence, the only difference is the condition. Here we want element to be divisible.
i.e.    arr[curr] % arr[prev] == 0 only then we will update the dp[curr] provided if dp[curr] < 1 + dp[prev]
        Here arr[curr] >= arr[prev] (array is sorted)

Note: For this question, it is fine to return any of the subarray, if multiple such subarray exists.

TC - O(nlogn) + O(n ^ 2) + O(n) for tracking and printing in worst case
SC - O(n)
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> hash(n, 0), dp(n, 1);       //Each element will be divisible by itself. At minimum, dp[i] = 1.
        int lastindex = 0;                      //For tracking the last element to be taken in subarray. We will start printing from here.
        int maxi = -1;                          //To help find the last element and can also be used to find the length of such subarray

        sort(nums.begin(), nums.end());         //Sort the array first.

        for(int i = 1; i < n; i++)
        {
            hash[i] = i;                //Initialize hash[i] with value i. We will use this later to print the subarray
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }

            if(dp[i] > maxi)
            {
                maxi = dp[i];
                lastindex = i;
            }
        }

        vector<int> temp;       //To store the subarray
        temp.push_back(nums[lastindex]);
        while(hash[lastindex] != lastindex)
        {
            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};

