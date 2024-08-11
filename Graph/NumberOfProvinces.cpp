// https://leetcode.com/problems/number-of-provinces/

/*
Approach 1: Breadth First Traversal using BFS 
A complete traversal can be made by repeatedly calling BFS each time with a new unvisited starting vertex.
TC - O(n * n) since input is a adjacency matrix. If it was adj list it would be O(V + E)
SC - O(n) Adj matrix is part of input therefore, not considered.

Note: Here n means vertex.
*/

class Solution {
public:
    void bfs(int &node, vector<int> &vis, vector<vector<int>> &adjMat)
    {
        int m = adjMat[0].size();
        queue<int> toVisit;
        toVisit.push(node);
        vis[node] = 1;

        while(!toVisit.empty())
        {
            int u = toVisit.front();
            toVisit.pop();

            for(int v = 0; v < m; v++)
            {
                if(adjMat[u][v] == 1 && vis[v] == 0)
                {
                    toVisit.push(v);
                    vis[v] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), noOfProvinces = 0;
        vector<int> vis(n + 1, 0);
        
        for(int u = 0; u < n; u++)
        {
            if(vis[u] == 0)
            {
                noOfProvinces++;
                bfs(u, vis, isConnected);
            }
        }

        return noOfProvinces;
        
    }
};

/*
Approach2: Depth first Traversal using DFS
TC - O(N * N) as all elements present in list/matrix will be processes ATMOST once.
SC - O(N) Visited array and stack space
*/

class Solution {
public:
    void dfs(int &node, vector<int> &vis, vector<vector<int>> &adjMat)
    {
        int n = adjMat[0].size();
        if(vis[node] == 0)
        {
            vis[node] = 1;
            for(int v = 0; v < n; v++)
            {
                if(vis[v] == 0 && adjMat[node][v] == 1)
                {
                    dfs(v, vis, adjMat);
                }
            }
        }

        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), noOfProvinces = 0;
        vector<int> vis(n + 1, 0);
        
        for(int u = 0; u < n; u++)
        {
            if(vis[u] == 0)
            {
                noOfProvinces++;
                dfs(u, vis, isConnected);
            }
        }

        return noOfProvinces;
        
    }
};


/*
Approach 3: Using Disjoint set
TC - O(n * n * α(n)) inverse Ackermann function, In any conceivable application of a disjoint-set data structure, α(n) <= 4
SC - O(n)

Note:
Rank -> Upper bound on the height of tree or distance between representative and farthest leaf node in tree.
Union by Rank is generally preferred when tree height is a key concern and when the problem involves 
operations that benefit from managing TREE HEIGHT directly.
Union by Size can be simpler and effective, particularly in cases where managing the size of each set is
more intuitive or when the problem naturally fits a size-based approach.

Mostly, we can pick either of two, based on ease of implementation. As time complexity is almost same for both in all practical purposes.
*/

class Solution {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), numProvinces = 0;
        initializeDisjointSet(n);

        for(int i = 0; i < n; i++)
        {
            // Checking right upper triangle only as matrix is symmetric
            // If (2, 4) is covered that means edge (4, 2) is also covered. We can avoid redundant operatons.
            for(int j = i + 1; j < n; j++)   
            {
                if(isConnected[i][j] == 1)
                    unionBySize(i, j);
            }
        }

        // We will calculate how many ultimate parents are there. And that is our number of provinces.
        // Rest all nodes are part of any of these provinces
        for(int i = 0; i < n; i++)
        {
            if(parent[i] == i)
                numProvinces++;
        }

        return numProvinces;
    }

    int findParent(int node)
    {
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);     // Path compression
    }

    // Performed on roots, not on individual nodes. So rank of Ultimate parents or roots might be updated
    void unionByRank(int u, int v)
    {
        int rootU = findParent(u), rootV = findParent(v);
        if(rootU == rootV)
            return;
        
        // As we are adding tree with less rank to tree with higher rank, overall tree rank will remain
        // unchanged and will still be equal to rank of tree having higher rank, in below case rank[rootV]
        if(rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else if(rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else if(rank[rootU] == rank[rootV]) // As rank of both are equal, rank of combined tree will increase by 1
        {
            parent[rootV] = rootU;
            rank[rootU] += 1;
        }

        return;
    }

    // Size remains unaffected by path compression, as the number of nodes for a root remains unchanged
    // Union is done on roots, so rank and size will be considered of roots
    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv)
            return;
        else if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        
        return;
    }

    void initializeDisjointSet(int n) 
    {
        rank.resize(n, 0);
        size.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;

        return;
    }
};
