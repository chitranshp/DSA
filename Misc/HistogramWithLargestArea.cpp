// https://leetcode.com/problems/largest-rectangle-in-histogram/

/*
Brute force solution:
Here we iterating over all possible rectangles and returning the maximum area.
TC - O(n * n)
SC - O(1)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        int curr, maxarea = 0, minh = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            minh = INT_MAX;     // We need to track minimum height for all 'i' separately.
            for(int j = i; j < n; j++)
            {
                // Height of rectangle formed by histograms, will be equal to the height of smallest histogram
                minh = min(heights[j], minh);   // For 3 1 5, at i = 0 and j = 2, rectangle will have h = 1 and w = 3
                curr = (j - i + 1) * minh;
                maxarea = max(curr, maxarea);
            }
        }

        return maxarea;
    }
};

/*
Approach 2: Optimized 

We can see that for a bar i, how far we can stretch the rectangle which includes ith bar towards right. The answer will be till we found an element which is smaller than ith bar.
And on left also, we can do it untill we find an element which is smaller then the ith bar on left.

area of ith bar rectangle = RSH[i] - LSH[i] + 1

For i = 1 in [1, 2, 1], we will consider the rectangle with width = 1 and height = 2
For i = 2 in [1, 2, 1], we will consider the rectangle with width = 3 and height = 1
TC - O(n)
SC - O(n) 
*/

class Solution {
public:
    /*
    Note1: We need this to find the position of the smallest histogram on left and right which in turn will be used to calculate the width and not to use it as actual height.
    Therefore, we will be tracking the left smallest height INDEX and same with next right smallest height INDEX.

    Creating Boundary for rectangle
    The bars having smallest height on left and smallest height on right are not acutally part of width of candidate rectangle. 
    But the bar 1 step AHEAD of smallest bar on left and one step BEFORE of smallest bar on right are the vertices of width.
    So, for ease of calculation and recording actual boundary of rectangle, for the left smallest height while pushing on stack, we will increment indexes by 1 and for right we will decrement indexes by 1. 
    So that they both are actually indexes of last bar on left which is PART OF rectangle and last bar on right which is PART OF rectangle.
    Now, both lsh and rsh will store the boundary of rectangle on left and right side for the rectangles formed

    In case no smallest value is present on left, we will store lsh[i] = 0, as in that case the last bar which will be part of rectangle will be 0th.
    And for right side, we will store rsh[i] = n - 1 due to the same reason.
    When we subtract them both say 6 and 3, we will get 3 but there are 4 bars in middle (since both points are included due to being vertices), we will add 1.
    Therefore width = rsh[i] - lsh[i] + 1
         0  1  2  3  4  5  6
    For [2, 1, 5, 6, 2, 3, 1]
    These are actually boundary while next smaller elements are one more than boundary
    lsh [0, 0, 2, 3, 2, 5, 0]   +1 for all except first
    rsh [0, 6, 3, 3, 5, 5, 6]  -1 for all except last
    */

    // Left Smallest height. 
    vector<int> helperLSH(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> lsh(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            // For comparison, we will use the index to get the acutal height from the vector
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            lsh[i] = (st.empty() == true) ? 0 : st.top() + 1;
            st.push(i); //wE are pushing the index of smallest(height) element not the acutal element
        }

        return lsh;
    }

    // Right smallest height
    vector<int> helperRSH(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> rsh(n, 0);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            rsh[i] = (st.empty() == true) ? n - 1: st.top() - 1;
            st.push(i);
        }

        return rsh;
    }

    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size(), maxarea = 0;
        vector<int> lsh = helperLSH(heights);
        vector<int> rsh = helperRSH(heights);

        for(int i = 0; i < n; i++)
            maxarea = max(maxarea, heights[i] * (rsh[i] - lsh[i] + 1));

        return maxarea;
    }
};

/*
TODO
Optimized approach2:

*/