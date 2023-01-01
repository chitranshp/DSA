// https://leetcode.com/problems/valid-sudoku/description/

//Optimised version using hashing
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int blocks[9][9] = {0};

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] != '.') 
                {
                    int c = board[i][j] - '1';          // 1 - '1' will be 0 and 9 - '1' will be 8.
                    int k = 3 * (i / 3) + j / 3;        // 3 * (i / 3) gives us vertical partition and 3 * (i / 3) + j / 3 takes us to the correct sub-block by adding horizontal column offset
                    
                    if(rows[i][c] || cols[j][c] || blocks[k][c])
                        return false;

                    rows[i][c] = 1;
                    cols[j][c] = 1;
                    blocks[k][c] = 1;
                }
            }
        }

        return true;
    }
};



/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board, int row = 0, int col = 0) 
    {
        int i = 0;
        if(row == 9) 
            return true;
        
        if(col >= 9)
            return isValidSudoku(board, row + 1, 0);

        if(board[row][col] != '.')
        {
            char ch = board[row][col];

            for(i = 0; i < 9; i++)
            {
                if(i != col && board[row][i] == ch)
                    return false;
                    
                if(i != row && board[i][col] == ch)
                    return false;

                int r = 3 * (row / 3) + i / 3;
                int c = 3 * (col / 3) + i % 3;

                if(board[r][c] == ch && (row != r || col != c))
                    return false;     
            }
        }

        return isValidSudoku(board, row, col + 1);
    }
};
*/
