// https://leetcode.com/problems/find-the-difference-of-two-arrays/

/*
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res = {{}, {}};
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());

        for(auto x: s1)
        {
            if(s2.count(x) == 0)
                res[0].emplace_back(x);
        }

        for(auto x: s2)
        {
            if(s1.count(x) == 0)
                res[1].emplace_back(x);
        }

        return res;
    }
};