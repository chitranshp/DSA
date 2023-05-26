// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

/*
Brute force: A simple brute force approach would be to stand at every cell and try to check whether the square can be increased till right diagonal element.
A necessary condition for that will be that other elements immediate right and bottom must also be one. Time complexity will be exponential.

Dynammic programming approach:
We will build another matrix of same size. 
Here each dp[i][j] represents the number of square submatrices whose right bottom vertex is at matrix[i][j].

Obviously, for first row and first column no such squares submatrices will exist other than that cell itself if it's containing one.

For filling out the remaining indices in dp table, we will use tabulation approach as we can already easilly fill first row and first column.
And we can use first row & first column values to fill the dp table sequentially from 2nd row/column.

    If the matrix cell (i, j) contains 0, we will set the value 0 to the cell dp[i][j].
    If the matrix cell (i, j) contains 1, we will first find the minimum value among the adjacent three cells i.e. min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]). And with that minimum value, we will add 1 and set it to the cell dp[i][j]. The formula will look like the following:
    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) +1


Note: This approach works as we are filling and calculating number of square submatrices ending at a particular cell sequentiall in a left to right manner. We can't do it randomly and expect to get the right answer

TC - O(m * n)
SC - O(m * n)
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        int totalsum = 0;

        for(int i = 0; i < m; i++)
            dp[i][0] = matrix[i][0];

        for(int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j] == 1)
        dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                else
                    dp[i][j] = 0;
            }
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                totalsum += dp[i][j];

        return totalsum;
    }
};