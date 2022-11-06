// https://leetcode.com/problems/maximum-difference-between-increasing-elements/

class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int minele = nums[0], maxdiff = -1;

        for(int i = 1; i < nums.size(); i++)
        {
            maxdiff = max(maxdiff, nums[i] - minele);
            minele = min(minele, nums[i]);
        }

        //It will be zero in the case of duplicate elements ex [1000, 10, 10]
        return (maxdiff == 0)? -1:maxdiff;
    }
};
