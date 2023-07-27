// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

/*
Point to Remember:
Unsorted sets: In C++ and Java, the key for an unordered set (e.g., std::unordered_set in C++ or HashSet in Java) must be HASHABLE, and this requirement is not met by vectors or lists by default. 
However, in the case of sorted sets (e.g., std::set in C++ or TreeSet in Java), the key must be SORTABLE, 
and vectors or lists can fulfill this requirement if their elements are sortable.

Therefore, for the below code unsorted_set<vector<int>> will not work whereas set<vector<int>> works fine.

Unsorted sets use Hashing and Sorted sets use some versin of BST and thus only require the key elements to be comparable using '<' operator.
*/

/*
Two islands are considered to be distinct if and only if one island is not equal to another (Rotation or reflection is out of scope of this problem)

Islands can be of below shapes also

        1 1           1 1    
        1 1             1
        1 1 1         1 1

Therefore, it is not possible to store their shape in the form of 2 * 3. 

            0 1 2 3 4 5
        0   1 1 0 0 0 0 
        1   1 1 0 0 0 0
        2   0 0 0 0 0 0
        3   0 0 0 0 0 0
        4   1 1 0 0 0 0
        5   1 1 0 0 0 0

Instead what we can do is use relative indexing by taking first discovered index of a particular island as base for that island.
And store all the coodrdinates calculated in this way in a set, so that we will have the count of only unique islands at the end.
For first island - 0 0 0 1 1 0 1 1      Base 0 0
For Second island- (4 -4) (0 - 0) (4 - 4) (1 - 0) (5 - 4) (0 - 0) (5 - 4) (1 - 0)     Base 4 0
                      0     0       0        1       1      0        1        1

We can see that for both islands, we are now getting the same sequence.  

Only thing to take care in this approach is that, we cannot explore randomly at any point. We should start our traversal with a sequence ex. Left, Right, Up, Bottom and continue with this same sequence 
for rest of the traversal through the grid. Else, we will get different coordinates for similar islands.

Since, it is fixed for every point that we store the coordinates in set, it will have two coordinates one for row and one for columns
We can use either set<vector<pair<int, int>>> or set<vector<int>>. Both will work absolute fine.

TC approx. O(n * m) * O(log(n * m)) + O(n * m * 4)
            For initial loop and set op.     For DFS call

SC - O(n * m) + O(n * m)
*/

class Solution {
  public:
    void dfs(vector<vector<int>> &grid, int r, int c, int row0, int col0, vector<vector<int>> &vis, vector<int> &res)
    {
        vis[r][c] = 1;
        res.push_back(r - row0);
        res.push_back(c - col0);
        
        int m = grid.size(), n = grid[0].size();
        int offsets[] = {0, 1, 0, -1, 0};
        
        for(int k = 0; k < 4; k++)
        {
            int nr = r + offsets[k], nc = c + offsets[k + 1];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 1)
            {
                dfs(grid, nr, nc, row0, col0, vis, res);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        unordered_set<vector<int>> unqIslands;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    vector<int> vec;
                    dfs(grid, i, j, i, j, vis, vec);
                    
                    // In worst case, the set will have whole elements of the grid, Therefore, TC for this will be O(log(n * m))
                    if(unqIslands.count(vec) == 0)
                        unqIslands.insert(vec);     // In case of duplicate islands, count will remain same.

                }
                
            }
        }
        
        return unqIslands.size();
    }
};


// Approach 2 using set<vector<pair<int, int>>>

// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &grid, int r, int c, int row0, int col0, vector<vector<int>> &vis, vector<pair<int, int>> &res)
    {
        vis[r][c] = 1;
        res.push_back({r - row0, c - col0});
        
        int m = grid.size(), n = grid[0].size();
        int offsets[] = {0, 1, 0, -1, 0};
        
        for(int k = 0; k < 4; k++)
        {
            int nr = r + offsets[k], nc = c + offsets[k + 1];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 1)
            {
                dfs(grid, nr, nc, row0, col0, vis, res);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> unqIslands;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    vector<pair<int, int>> vec;
                    dfs(grid, i, j, i, j, vis, vec);
                    
                    if(unqIslands.count(vec) == 0)
                        unqIslands.insert(vec);     // In case of duplicate islands, count will remain same.
                }
                
            }
        }
        
        return unqIslands.size();
    }
};