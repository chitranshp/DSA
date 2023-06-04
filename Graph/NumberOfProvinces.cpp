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


