// https://leetcode.com/problems/valid-sudoku/description/

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
