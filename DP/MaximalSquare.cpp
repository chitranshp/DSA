// https://leetcode.com/problems/maximal-square/

/*
Approach 1: Every square is also a rectangle
In maximal rectangle, for every bar(histogram) we try to include as much width as possible for calculating area through that bar.
But for square, we will calculate the height and width. Then we will take the minimum of height and width as the side of square.
And using that side calculate the area of square. Every other step will be same as maximal-rectangle problem.
TC - O(m * (n + n))
SC - O(n)
*/

class Solution {
public:
    int largestSquareArea(vector<int>& heights) 
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

                int side = min(h, w);

                maxarea = max(maxarea, side * side);
            }

            st.push(i);
        }

        return maxarea;
    }

    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxarea = 0;

        for(int i = 0; i < m; i++)    
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            maxarea = max(maxarea, largestSquareArea(heights));
        }

        return maxarea;
    }
};