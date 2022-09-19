//https://leetcode.com/problems/next-greater-element-i/
/* The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
    unordered_map<int, int> findnum;
    stack<int> st;
        
    for(int i = nums2.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= nums2[i])
            st.pop();
            
        if(st.empty())
        {
            findnum[nums2[i]] = -1;
            st.push(nums2[i]);
        }
        else
        {
            findnum[nums2[i]] = st.top();
            st.push(nums2[i]);
        } 
    }
        
    for(int i = 0; i < nums1.size(); i++)
        nums1[i] = findnum[nums1[i]];
        
    return nums1;
}

int main()
{
    vector<int> nums1 = {2,4}, nums2 = {1,2,3,4};
    nums1 = nextGreaterElement(nums1, nums2);

    for(auto it: nums1)
        cout<<it<<" ";

    return 0;
}