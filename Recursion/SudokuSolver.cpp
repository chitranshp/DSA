// https://leetcode.com/problems/sudoku-solver/description/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        solver(board);
    }

    bool solver(vector<vector<char>>& board)
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++)
                    {
                        if(isvalid(board, i, j, c) == true)
                        {
                           board[i][j] = c;

                           if(solver(board) == true)
                                return true;                       
                            else
                                board[i][j] = '.'; 
                        }
                            
                    }

                    return false;
                }
            }
        }

        return true;        //If it does not execute the loop body, that means no place is empty. All are filled with valid entries. Therefore, return true.
    }

    bool isvalid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[row][i] == c)        //Checks whole row
                return false;

            if(board[i][col] == c)        //Checks whole column
                return false;

            //Checks the 3 X 3 sub matrix
            /*
                [0-8][0-8]
                Row-wise and column-wise, the whole sudoku can be divided into 3 horizontal partitions and 3 vertical partitions with each partition of size 3. 
                On dividing row index by 3 and column index by 3, we get the partition index fof an element both horizontal and vertical.
                On multiplying that partition index by 3 again, we get the index of first element in submatrix. For ex. element at (5, 7)
                (5 / 3) = 1st vertical partition  (Indexing is done from 0)
                (7 / 3) = 2nd horizontal partition

                Now, 3 * (5 / 3) = 3 which is the row for first element in that submatrix
                And, 3 * (7 / 3) = 6 which is the col for first element in that submatrix

                i / 3 = 0 for i values 0,1,2
                i % 3 = 0,1,2 for i values 0, 1, 2

                These are used to iterate over the submatrix starting from first element of that submatrix.

                The element at board[row][col] will be '.' for this function.
            */
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }

        return true;
    }
};
