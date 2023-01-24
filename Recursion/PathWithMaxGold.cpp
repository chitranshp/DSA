// https://leetcode.com/problems/path-with-maximum-gold/submissions/884541491/

class Solution {
public:
    int helper(vector<vector<int>>& grid, int row, int col)
    {
        if(row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 || grid[row][col] <= 0)
            return 0;

        grid[row][col] = -grid[row][col];

        int up = helper(grid, row - 1, col);
        int down = helper(grid, row + 1, col);
        int left = helper(grid, row, col - 1);
        int right = helper(grid, row, col + 1);
        
        grid[row][col] = -grid[row][col];   //Backtrack

        return grid[row][col] + max({up, down, left, right});
    }

    int getMaximumGold(vector<vector<int>>& grid) 
    {
        int maxgold = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                maxgold = max(maxgold, helper(grid, i, j));

        return maxgold;
    }
};
