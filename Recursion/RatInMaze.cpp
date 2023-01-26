// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// User function template for C++

// TC O(4^(n*n))
class Solution{
    public:
    bool dfs(vector<vector<int>> &m, int row, int col, string path, vector<string>& allpaths, int& n)
    {
        if(row == n - 1 && col == n - 1 && m[row][col] == 1)
        {
            allpaths.push_back(path);
            return true;
        }
        
        if(row < 0 || col < 0 || row >= n || col >= n || m[row][col] <= 0)
            return false;
        
        m[row][col] = m[row][col] * -1;
        bool down = dfs(m, row + 1, col, path + 'D', allpaths, n);
        bool left = dfs(m, row, col - 1, path + 'L', allpaths, n);
        bool right = dfs(m, row, col + 1, path + 'R', allpaths, n);
        bool up = dfs(m, row - 1, col, path + 'U', allpaths, n);
        m[row][col] = m[row][col] * -1;
        
        return up || down || left || right;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        string path = "";
        vector<string> allpath;
        
        dfs(m, 0, 0, path, allpath, n);
        
        return allpath;
    }
};
