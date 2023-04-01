//https://practice.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1

/*
Approach 2 - We will take a dp vector of size 'n' inititialized with 1. For each element, ignoring all the previous elements LIS will be 1 ie the subsequence will be element itself.
dp[i] will represent the LIS that ends at index 'i'(including i).

So, For an index 'i' we will go through all the index from 0 to 'i - 1'(prevind). And if nums[prevind] < nums[i], we will update dp[i] value as max(dp[i], 1 + dp[prevind]). 
Here 1 is added to the dp[prevind] to include the 'i' the element in LIS.

For printing, the LIS we will need the previndex as well for backtracking.
We will declare another array 'hash' with each element initialized to it's index. We will use this property to validate whether we have reached the beginning of our LIS while backtracking.
Now while calculating LIS, whenver we are updating the dp[i], we will store the previndex in hash[i].
After whole dp and hash vector is filled. We will backtrack in hash array from the index containing LIS in dp

For storing LIS values while backtracking, we can store them in dp vector itself. As we only need hash to backtrack.
Or we can use a separate vector to store the elements in reverse order and return the reversed vector.
TC - O(N ^ 2)
SC - O(N)
*/

class Solution {
public:
    vector<int> LIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n, 0);
        int maxi = 0, lastindexofLIS = 0;    //lastindex is to keep the index of last element of LIS. We will start backtracking from here.

        for(int index = 0; index < n; index++)
        {
            hash[index] = index;
            for(int prevind = 0; prevind <= index - 1; prevind++)
            {
                if(nums[index] > nums[prevind] && dp[index] < 1 + dp[prevind])
                {
                    dp[index] = 1 + dp[prevind];
                    hash[index] = prevind;
                }   

                if(dp[index] > maxi)
                {
                    maxi = dp[index];
                    lastindexofLIS = index;     //Keep track of the index of last element of LIS
                }
            }
        }

        vector<int> lis;
        lis.push_back(nums[lastindexofLIS]);

        //If we reach an element in hash such that hash[i] = i, this means that we have reached the first index of our LIS which in reverse order means last.
        while(hash[lastindexofLIS] != lastindexofLIS)
        {
            lastindexofLIS = hash[lastindexofLIS];
            lis.push_back(nums[lastindexofLIS]);
        }

        reverse(lis.begin(), lis.end());

        return lis;

        /*
        Alternative way to not create extra vector for storing LIS
            dp.resize(maxi);                        
            dp[maxi - 1] = arr[lastindexofLIS];         //If maxi = 5, then dp[0.....4] will store our LIS
            while(hash[lastindexofLIS] != lastindexofLIS)
            {
                --maxi;
                lastindexofLIS = hash[lastindexofLIS];
                dp[maxi - 1] = arr[lastindexofLIS];
            }
            
            return dp;
        */
    }
};


