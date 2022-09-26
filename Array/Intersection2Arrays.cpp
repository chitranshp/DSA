//https://leetcode.com/problems/intersection-of-two-arrays/
/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set freq(nums1.begin(), nums1.end());
        vector<int> res;
        for(auto x:nums2)
         if(freq.count(x))
            {
                res.push_back(x);
                freq.erase(x);
            }
        
    }
};