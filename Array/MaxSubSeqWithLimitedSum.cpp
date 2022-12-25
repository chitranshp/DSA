// https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        // We only care about the sum of subsequence of max. size not order. For ex. [2, 1 , 3] or [3,1,2] or [1,2,3] and query [3]. Answer would be 2. (1 and 2)
        // Therefore, we sort it as for max size, we will need to fill smaller elements
        sort(nums.begin(), nums.end());     //nlogn

        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];         //n

        for(int q = 0; q < queries.size(); q++)     //mlogn where m is the size of queries
            queries[q] = upper_bound(nums.begin(), nums.end(), queries[q]) - nums.begin();

        return queries;
    }

    //Total = (m + n)logn
};
