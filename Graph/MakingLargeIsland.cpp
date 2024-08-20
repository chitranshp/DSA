// https://leetcode.com/problems/making-a-large-island/

/*
TC - O(m * n * alpha(m * n)) 
SC - O(m * n);

Alternative approach without DSU: Use DFS to explore islands and colour each group of islands with unique colour(set grid[i][j] with a integer >= 1). And map each colour to the size of island component in a map.
Conversion and size calculation will remain similar to this. Complexity will be O(m * n)
*/

class DisjointSet 
{   
    public:
    vector<int> parent, size;

    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int findParent(int x)
    {
        if(parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
    }
    
    void unionBySize(int u, int v)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);
        
        if(parentU == parentV)
            return;
            
        if(size[parentU] < size[parentV])
        {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else if(size[parentU] >= size[parentV])
        {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
        
        return;
    }
};

class Solution {
public:
    bool isValid(int &r, int &c, int &m, int &n)
    {
        if(r >= 0 && c >= 0 && r < m && c < n)
            return true;
        
        return false;
    }

    int findMaxSizeAfterConversion(DisjointSet &ds, vector<vector<int>>& grid) 
    {   
        int maxIslandSize = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> directions = {0, 1, 0, -1, 0};
        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(grid[r][c] == 1)
                    continue;

                if(grid[r][c] == 0) 
                {
                    int tempSize = 1;   // Initial value as 1, As it will increase size of current island by 1 atleast.
                    unordered_set<int> uniqueComponents;
                    for(int k = 0; k < 4; k++)
                    {
                        int nr = r + directions[k], nc = c + directions[k + 1];

                        if(isValid(nr, nc, m, n) && grid[nr][nc] == 1)
                        {
                            int adjNode = n * nr + nc;
                            int uParent = ds.findParent(adjNode);

                            /*
                            1
                        1   0   0        1. If all or some of these nodes belong to same component, we will skip rest of them using storing Parent in unordered set.
                            1            2. If all are part of different components, that means it will join all of them in a single island. In that case, we add the size of all non 0 cells along with our intial size of 1.
                            */

                            // To avoid nodes belonging to prevously processed components.
                            if(uniqueComponents.find(uParent) == uniqueComponents.end())
                            {
                                tempSize += ds.size[uParent];
                                uniqueComponents.insert(uParent);
                            }
                        }
                    }
                
                maxIslandSize = max(maxIslandSize, tempSize);
                }
            }
        }

        return maxIslandSize;
    }

    int largestIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;

        int m = grid.size(), n = grid[0].size();
        vector<int> directions = {0, 1, 0, -1, 0};
        DisjointSet ds(m * n);
        int maxIslandSize = 0, maxSizeBeforeConversion = 0;

        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(grid[r][c] == 0)
                    continue;
                
                int node = n * r + c;
                if(grid[r][c] == 1)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int nr = r + directions[k], nc = c + directions[k + 1];
                        if(isValid(nr, nc, m, n) && grid[nr][nc] == 1)
                        {
                            int adjNode = n * nr + nc;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }

                // Finding max island size before conversion in same pass. This is done only after all 4 union operation is done for node.
                maxSizeBeforeConversion = max(maxSizeBeforeConversion, ds.size[ds.findParent(node)]);  
            }
        }

        maxIslandSize = max(findMaxSizeAfterConversion(ds, grid), maxSizeBeforeConversion);
        return maxIslandSize;
    }
};
