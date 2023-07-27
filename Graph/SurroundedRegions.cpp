// https://leetcode.com/problems/surrounded-regions/

class Solution {
private:
    /*
    TC -> For DFS, O(n * m * 4) as it is adj Matrix and we are checking in 4 directions for '0'. And in worst case assume all are 0's. + O(n) + O(m) = O(n * m)

    SC - O(n * m). Stack space for worst case, i.e. when all element are 0's.
    */
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &board)
    {
        vis[r][c] = 1;
        int offset[] = {0, 1, 0, -1, 0};
        int m = board.size(), n = board[0].size();

        for(int k = 0; k < 4; k++)
        {
            int nr = r + offset[k], nc = c + offset[k + 1];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0 && board[nr][nc] != 'X')
            {
                dfs(nr, nc, vis, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        // Traverse first row & last row
        for(int j = 0; j < n; j++)
        {
            // First row
            if(vis[0][j] == 0 && board[0][j] != 'X')
            {
                dfs(0, j, vis, board);
            }

            // Last row
            if(vis[m - 1][j] == 0 && board[m - 1][j] != 'X')
            {
                dfs(m - 1, j, vis, board);
            }
        }

        for(int i = 0; i < m; i++)
        {
            // First column
            if(vis[i][0] == 0 && board[i][0] != 'X')
            {
                dfs(i, 0, vis, board);
            }

            // Last column
            if(vis[i][n - 1] == 0 && board[i][n - 1] != 'X')
            {
                dfs(i, n - 1, vis, board);
            }
        }

        for(int i = 1; i < m - 1; i++)
            for(int j = 1; j < n - 1; j++)
                if(vis[i][j] == 0 && board[i][j] != 'X')
                    board[i][j] = 'X';

        return;
    }
};