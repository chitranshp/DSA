// https://leetcode.com/problems/design-tic-tac-toe/description/

/*
Brute Force;
For every move:
1. Check entire row which has that cell
2. Check entire column which contains that cell
3. If row == col, only then check main diagonal
4. If row + col == n - 1, only then check anti diagonal

TC - O(n * n) for board initialization + O(n) for each move and at most O(n ^ 2) calls will be made to move as per question(all moves are valid). 
     Therefore total O(n ^ 3)
SC - O(n * n) for board
*/

class TicTacToe {
    vector<vector<int>> board;
    bool gameFinished;
    int n;

public:
    TicTacToe(int n) {
        board.assign(n, vector<int>(n, 0)); // For each cell, we only want to store 1 value
        this->n = n;
        gameFinished = false;
    }
    
    int move(int row, int col, int player) {
        // Game was already finished in prior moves. No further move allowed
        if(gameFinished == true)
            return -1;      

        if(board[row][col] == 0)
        {
            board[row][col] = player;
            if(winCondition(row, col, player))
            {
                gameFinished = true;
                return player; 
            }   
            else
                return 0;
        }

        gameFinished = true;        // All cells have been filled and game has finished
        return 0;                   // Match has drawn
    }

    bool winCondition(int row, int col, int player) {
        if(checkHorizontal(row, player) || checkVertical(col, player))
            return true;

        if(row == col && checkDiagonal(player))
            return true;

        if(row + col + 1 == n && checkAntiDiagonal(player))
            return true;

        return false;
    }

    bool checkHorizontal(int row, int player) {
        for(int p = 0; p < n; p++)
        {
            if(board[row][p] != player)
                return false;
        }   
        return true;
    }

    bool checkVertical(int col, int player) {
        for(int p = 0; p < n; p++)
        {
            if(board[p][col] != player)
                return false;
        }   
        return true;
    }

    bool checkDiagonal(int player) {
        for(int p = 0; p < n; p++)
        {
            if(board[p][p] != player)
                return false;
        }   
        return true;
    }

    bool checkAntiDiagonal(int player) {
        for(int p = 0; p < n; p++)
        {
            if(board[p][n - p - 1] != player)
                return false;
        }   
        return true;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

// Optimized approach
/*
It is given that all moves are valid and there are two players only. So, we count number of moves for each row and each column with respect to each player in rows[n] and cols[n]
If player 1 makes a move in row 1, we increase row1 counter with +1 and -1 for player 2. If it reaches n, this means all cells in row1 were marked by player 1 and for -1, means all cells were marked by player 2
And as there are only 1 diagonal & antidiagonal, we can use just 1 int variable for both of them which will be diagonal & antiDiagonal.
It is important to intitalize all counters with 0 for this approach

We check win condition after each move. So, if after any move, win condition is achieved abs(diagonal) == n return the current player as winner
TC - O(n * n) for vector initialisation. And O(1) per move
     With total O(n * n) max moves, this will be O(n * n) for entire game in worst case and O(1) per move
SC - O(n * n) for board and O(n) for other data structures
*/

class TicTacToe {
    vector<vector<int>> board;
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antiDiagonal;
    bool gameFinished;
    int n;

public:
    TicTacToe(int n) {
        board.assign(n, vector<int>(n, 0)); 
        this->n = n;
        gameFinished = false;

        rows.assign(n, 0);
        cols.assign(n, 0);
        diagonal = 0;
        antiDiagonal = 0;
    }
    
    int move(int row, int col, int player) {
        // Game has finished in one of previous moves. No further move allowed
        if(gameFinished == true)    
            return -1;

        if(board[row][col] == 0)
        {
            int delta = (player == 1) ? 1: -1;
            board[row][col] = player;
            rows[row] += delta;
            cols[col] += delta;
            if(row == col)
                diagonal += delta;
            
            if(row + col + 1 == n)
                antiDiagonal += delta;

            if(winCondition(row, col, player))
            {
                gameFinished = true;
                return player; 
            }   
            else
                return 0;           // No one has won yet
        }

        gameFinished = true;        // All cells have been filled and game has finished
        return 0;                   // Game is drawn
    }

    // If a row/column/diagonal are all marked by same player, value will be n or -n (depending on player)
    bool winCondition(int row, int col, int player) {
        // Check for row and column and find if player has won
        if(abs(rows[row]) == n || abs(cols[col]) == n)
            return true;

        // Check for diagonals and find if player has won
        if(abs(diagonal) == n || abs(antiDiagonal) == n)
            return true;

        return false;
    }
};
