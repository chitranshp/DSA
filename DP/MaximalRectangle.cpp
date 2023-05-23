// https://leetcode.com/problems/maximal-rectangle/


/*
            1 0 1 0 0
            1 0 1 1 1
            1 1 1 1 1

We can represent row 1 as histogram with bar heights 1 0 1 0 0
                 row 2                               2 0 2 1 1
                 row 3                               3 1 3 2 2  These are heights of histogram bars
                 We can see that largest rectangle will have width of 3 and height of 2. Therefore area of 6.
                 We just have to see the largest rectangle formed by these and return it's area.

So, we can convert this problem into HistogramWithLargestArea
For converting to histogram, first we will take a 1-d vector of size n and treat it as it is containing height of histogram bars, and for each row, if jth column is 1, we will increment that cell by 1 and for zero set it as 0.
We are using the past height and using it to decide the current height. We can say that we are kind of memoizing the cell values in form of height.
TC -O(m * (n + n)) We are not calling largestRectangleArea only once per row.
SC - O(n)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size(), maxarea = 0;
        stack<int> st;

        for(int i = 0; i <= n; i++)
        {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int h = heights[st.top()];
                st.pop();

                int w;
                if(st.empty())  
                    w = i;     
                else           
                    w = i - st.top() - 1; 

                maxarea = max(maxarea, h * w);
            }

            st.push(i);
        }

        return maxarea;
    }

    
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxarea = -1;

        for(int i = 0; i < m; i++)                      // O(m)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            int area = largestRectangleArea(heights);   // O(n)
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};