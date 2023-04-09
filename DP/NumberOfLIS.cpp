// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

/*
                         0  1  2  3  4  5  6  7  8   9  
        If our array is {1, 5, 4, 3, 2, 6, 7, 10, 8, 9}
                then dp {1, 2, 2, 2, 2, 3, 4,  5, 5, 6}
                count   {1, 1, 1, 1, 1, 4, 4,  4, 4, 4}

    For dp[3] count[3] is 1 because there is only 1 LIS at index 3 of length 2 which is {1, 3}
    for dp[9] count is due to {{1, 5, 6, 7, 8, 9}, {1, 4, 6, 7, 8, 9}, {1, 3, 6, 7, 8, 9},
    {1, 2, 6, 7, 8, 9}}

                When arr[i] > arr[j] && dp[i] < 1 + dp[j] for i = 5 and j = 1 initially dp[i] = 1 and cnt[i] = cnt[j] = 1
                     dp[5] = 1 + dp[1] = 3
                Only Possible Longest increasing subseq at i = 5 and **j = 1** is {1, 5, 6} 
                For cnt[1] = {1, 5}. We are just adding 6 at the end of {1, 5}. We are not creating a totally new subsequence.
                Therefore, cnt[i] inherits the value of cnt[j] when arr[i] > arr[j] && dp[i] < 1 + dp[j].
                All subsequences covered under dp[j] just get appended by nums[i]. 
                Therefore, count of subsequences will still remain cnt[j].

                When arr[i] > arr[j] && dp[i] == 1 + dp[j]. for i = 5 and j = 2 initially dp[i] = 1 and cnt[i] = cnt[j] = 1
                This means that there is another set of subsequences for which if we append nums[i] at the end, we can get
                another set of subsequences of same length as dp[i] which is equal to 1 + dp[j] (+1 is to show nums[i] is being appended to all those subsequences)
                For j = 2, we have {1, 4} subseq to which we add we get another subseq {1, 4, 6} of length 3 for i = 5 and j = 2
                This length 3 is same as current longest increasing subseq length. 
                And this subseq is totally new. Meaning this was not covered under subseq under current val of cnt[5] = 1 {1, 5, 6}

                Therefore for this case, we update cnt[i] = cnt[i] + cnt[j]
                                                            {1, 5, 6} + {1, 4, 6} = {{1, 5, 6}, {1, 4, 6}}

                Simultanously, while calculating LIS, we will keep track of longest length.

                After whole LIS is calculated, we will keep adding count of subsequences for all indexes for which dp[i] == Length of longest increasing subseq.


If dp[i] = 3 and cnt[i] = x, this means there are 'x' longest increasing subsequences of legnth 3.


Count does not track all POSSIBLE INCREASING subsequences. It only does for LONGEST INCREASING SUBSEQUENCES POSSIBLE FOR THAT INDEX. And whenever we find a new longest increasing subsequence, we update the count with the new value for that length by inheriting it from the previous index.
Or if we find another subsequence which is equal to same length, we add the count for that to our current count.

TC - O(n ^ 2)
SC - O(n)
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        int maxi = -1;
        vector<int> dp(n, 1), cnt(n, 1);        //Every element in itself is LIS therefore, number of LIS till that will be atleast 1.

        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[i] > nums[j] && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                }
                else if(nums[i] > nums[j] && dp[i] == 1 + dp[j])
                    cnt[i] = cnt[i] + cnt[j];
            }

            if(dp[i] >= maxi)       //To track the length of longest increasing subsequence.
            {
                maxi = dp[i];
            }
        }

        int res = 0;
        //Here, we will iterate through whole dp array and for whichever index, we find dp[i] == maxi, we will add it to our count of number of longest increasing subsequences.
        //Case when [2, 2, 2, 2, 2] maxi = 1 and dp will be [1, 1, 1, 1, 1]
        for(int i = 0; i < n; i++)
        {
            if(dp[i] == maxi)
                res = res + cnt[i];
        }

        return res;
    }
};