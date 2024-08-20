// https://www.geeksforgeeks.org/problems/number-of-islands/1

/*
Why disjoint set if of size n * m and not n or n + m?
Here we are tracking and checking for land cells, in worst case there could be n * m land cells. So, we need to track each land cell and check whether it is connected to land cell or not.
Therefore, we are using a disjoint set of size n * m. Unlike, provinces problem where, we are only checking if two provinces are connected or not. And total 'n' provinces are there.

TC - O(k×α(n×m))
SC - O(n * m)
*/

class DisjointSet 
{
    private:
    vector<int> parent, size;
    
    public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int idx[] = {1, 0, -1, 0, 1};
        vector<int> res;
        int cnt = 0;
        
        for(vector<int> &vec: operators)
        {
            int r = vec[0], c = vec[1];
            if(vis[r][c] == 1)      // If we get a cell which has already been converted to land previously
            {
                res.push_back(cnt);
                continue;
            }
                
            vis[r][c] = 1;
            int node = m * r + c;       // Corresponding node for [r,c] in disjoint set
            cnt++;              // Initially for every new land cell, increase total number of islands by 1
            
            // If the new cells if found to be connected to any other island group, decrease number of islands by 1.
            for(int i = 0; i < 4; i++)
            {
                int adjr = r + idx[i], adjc = c + idx[i + 1];
                int adjNode = m * adjr + adjc;
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m && vis[adjr][adjc] == 1)
                {
                    if(ds.findParent(node) != ds.findParent(adjNode))
                    {
                        cnt--;
                        ds.unionBySize(node, adjNode);
                    }
                    else    // Scenario: If top and rightmost cell both are connected, island count will be decremented once only in first if condition(Which will be trigerred for whichever neighbour is checked first for land cell)
                    {
                        continue;   
                    }
                }
            }
            
            res.push_back(cnt);
        }
        
        return res;
    }
};
