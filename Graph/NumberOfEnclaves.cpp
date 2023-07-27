// https://leetcode.com/problems/number-of-enclaves/

/*
MultiSource BFS
SC - O(n * m)
TC - O(n * m * 4)
*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size(), cntOfEnclaves = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // A land located at boundary(We can go off the grid using this)
                if((i == 0 || j == 0 || i == m - 1 ||  j == n - 1) && grid[i][j] == 1)
                {

                    q.push(make_pair(i, j));
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int offsets[] = {0, 1, 0, -1, 0};

            for(int k = 0; k < 4; k++)
            {
                int nr = r + offsets[k], nc = c + offsets[k + 1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 1)
                {
                    q.push(make_pair(nr, nc));
                    vis[nr][nc] = 1;    // We will mark vis for all land cells with 1 indicating that, it is possible to walk off the grid using it.
                }
            }
        }

        for(int i = 1; i < m - 1; i++)
            for(int j = 1; j < n - 1; j++)
                if(vis[i][j] == 0 && grid[i][j] == 1)
                    cntOfEnclaves++;

        return cntOfEnclaves;
    }
};