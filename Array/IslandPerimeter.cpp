// https://leetcode.com/problems/island-perimeter/description/

/*
TC - O(m * n)
SC - O(m * n)
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                int curr = 0;
                if(grid[i][j] == 1)
                {
                    if(i - 1 < 0 || grid[i - 1][j] == 0)
                        curr += 1;
                    if(i + 1 >= grid.size() || grid[i + 1][j] == 0)
                        curr += 1;
                    if(j - 1 < 0 || grid[i][j - 1] == 0)
                        curr += 1;
                    if(j + 1 >= grid[0].size() || grid[i][j + 1] == 0)
                        curr += 1;

                    perimeter += curr;
                }
            }
        }

        return perimeter;
    }
};