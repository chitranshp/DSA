// https://leetcode.com/problems/word-search/submissions/883150820/

class Solution {
public:
    bool searchNext(vector<vector<char>>& board, int i, int j, string &word, int index)
    {
        if(index == word.size())
            return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index] || board[i][j] == '-')
            return false;

        char ch = board[i][j];
        board[i][j] = '-';  //To prevent same cell being used twice down the recursion tree.

        bool top = searchNext(board, i - 1, j, word, index + 1);
        bool left = searchNext(board, i, j -1, word, index + 1);
        bool right = searchNext(board, i, j + 1, word, index + 1);
        bool down = searchNext(board, i + 1, j, word, index + 1);

        board[i][j] = ch; //To backtrack

        return top || left || right || down;
    }
    
    bool exist(vector<vector<char>>& board, string& word, int index = 0) 
    {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == word[index])
                    if(searchNext(board, i, j, word, index))
                        return true;
            }

        return false;
    }
};
