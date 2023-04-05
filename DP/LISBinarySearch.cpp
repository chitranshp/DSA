// https://leetcode.com/problems/longest-increasing-subsequence/description/

/*
        1, 7, 8, 4, 6, -1, 9
    Let's calculate length of LIS for this array.
        1, 7, 8, 9
        1, 4, 6, 9
       -1, 9

    Since, we are only considered length of LIS instead of the actual LIS, instead of storing multiple subsequences
    and tracking through them. We can just keep one subsequence and keep on overwriting it.
    For ex. instead of 3 subsequences, we can keep

        1, 7, 8
    When 4 comes, we can overwrite 7 with 4. As keeping 7 there serves us no purpose and future values also won't be affected. As they only depend on the largest value at the end which is unchanged.
        1, 4, 8
    When 6 comes
        1, 4, 6
    When 9 comes
        1, 4, 6, 9
    The length of LIS that we get is 4. 
    THIS TEMPRORY ARRAY DOES NOT REPRESENT THE LIS, IT JUST REPRESENTS THE LENGTH OF LIS.

    To find the the place for which we do the replacement, we can use binary seach. Since, the subsequence is increasing(Sorted in ascending order.)

TC - O(nlogn)
SC - O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> lis;
        lis.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > lis.back())
                lis.push_back(nums[i]);
            else
            {
                int pos = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();       //Return an iterator to the first value which is greater then nums[i]. On subtracting lis.begin(), we get the number of element between first and that poined by iterator(5 - 2 = 3) which is same as 0 - based index. 
                lis[pos] = nums[i];
            }
        }

        return lis.size();
    }
};
