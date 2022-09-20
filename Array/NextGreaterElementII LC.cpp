//https://leetcode.com/problems/next-greater-element-ii/

/* Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
*/


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        stack<int> st;
        int nge, n = nums.size();
        vector<int> res(n, -1);

        
        for(int i = 2 * n - 1; i >= 0; i--)
        {
            while(!st.empty()  && nums[i % n] >= st.top())
                st.pop();
            
            if(st.empty())
            {
                nge = -1;
                st.push(nums[i % n]);
                res[i % n] = nge;
            }
            else
            {
                nge = st.top();
                st.push(nums[i % n]);
                res[i % n] = nge;
            }
        }
        return res;
    }
};