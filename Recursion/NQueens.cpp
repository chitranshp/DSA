// https://leetcode.com/problems/n-queens/description/

class Solution {
public:
/*
    bool isSafe(vector<string> board, int r, int c, int n)  //O(3n) = O(n)
    {
        int row = r, col = c;

        //Check left horizontal
        while(col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;

            col--;
        }

        //Check lower diagonal
        row = r;
        col = c;
        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
                
        }

        row = r;
        col = c;
        while(row < n && col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;

            row++;
            col--;
        }

        return true;
    }
*/

    void solve(vector<vector<string>> &solutions, vector<string> &board, int n, int col, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
    {
        if(col == n)
        {
            solutions.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++)
        {
            /*
            if(isSafe(board, row, col, n))
            {
                board[row][col] = 'Q';
                solve(solutions, board, n, col + 1);
                board[row][col] = '.';
            }
            */

            //Using Hashing to find whether a position is valid or not - O(1)
            if(leftRow[row] != 1 && upperDiagonal[n - 1 + col - row] != 1 && lowerDiagonal[row + col] != 1)
            {
                 board[row][col] = 'Q';
                 leftRow[row] = 1;
                 lowerDiagonal[row + col] = 1;
                 upperDiagonal[n - 1 + col - row] = 1;
                 solve(solutions, board, n, col + 1, leftRow, upperDiagonal, lowerDiagonal);
                 board[row][col] = '.';
                 leftRow[row] = 0;
                 lowerDiagonal[row + col] = 0;
                 upperDiagonal[n - 1 + col - row] = 0;

            }

        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> res;
        vector<string> board(n);
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);

        string s(n, '.');

        for(int i = 0; i < n; i++)
            board[i] = s;

        solve(res, board, n, 0, leftRow, upperDiagonal, lowerDiagonal);

        return res;
    }
};
