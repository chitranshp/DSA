//https://leetcode.com/problems/intersection-of-two-arrays-ii/
/* Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order. */


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
       unordered_map<int, int> um;
       vector<int> res;
        
       for(auto x: nums1)
           um[x]++;
       for(auto x : nums2)
           if(um[x] >= 1)
           {
               um[x]--;
               res.push_back(x);
           }
        return res;
    }
};