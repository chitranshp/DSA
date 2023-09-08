// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

/*
In case of directed graph, while traversing through dfs if we reach a node that has been already visited once and is not the parent of current node, then we would have reached a cyle.
But in directed graph, 

            1 -> 2 -> 3 -> 4
                      |    | 
                      V    V
                      7 -> 5 -> 6

If we start from 1, we explore 1 -> 2 -> 3 -> 4 -> 5 -> 6. From 6, it will return and on 3, it will explore the other
unexplored path from 3 -> 7 -> 5. As 5 i already visited, it will detect a loop here. But it's not a loop as 
3 is not reachable from 7.

So, in case of DFS, we have to modify the algorithm such that it only detects a loop, if we reach an 
already visited vertex WHILE TRAVERSING DOWN THE SAME PATH.

We can use a another array similar to vis, where we assign a node value as 1, when it's visited.
Note: While backtracking, if no loop is detected, we should be setting it's value back to 0. So, that for the next path, it is reset.
And since, it's directed graph, we don't need to validate that the already visited node is not the parent of current node.

Note: Instead of two arrays, we can use one single vis array where 0 indicates not visited, 1 indicates visited but not on same path and 2 indicates visited and on same path.
    2. Instead of pathVis, inStack vector name will be better as those nodes indicate that they were visited in the current recursion stack.

TC - O(V + E)
SC - O(2V) + O(V) Vis + pathVis + Recursion stack space.
*/

class Solution {
  private:
    bool dfs(int V, vector<int> adj[], bool vis[], bool pathVis[], int source)
    {
        vis[source] = 1;
        pathVis[source] = 1; // Mark that this node is visited while traversing the current path
        
        for(int node: adj[source])
        {
            if(vis[node] == 0)
            {
                if(dfs(V, adj, vis, pathVis, node) == true)
                    return true;
            }
            // If node is visited and while traversing the same path
            else if(vis[node] == 1 && pathVis[node] == 1)  // or we can directly check pathVis[node] == 1.
                return true;
        }
        
        pathVis[source] = 0;        // Backtrack
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        bool vis[V] = {0}, pathVis[V] = {0};
        
        // As there can be disconnected components
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
                if(dfs(V, adj, vis, pathVis, i) == true)        // If it returns false, i.e. no loop is detected, it will continue to check for other unexplored vertices.
                    return true;
        }
        
        return false;
    }
};

// Approach 2: Using only one visited array

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int V, vector<int> adj[], vector<int> &vis, int u)
    {
        vis[u] = 2;     // Visited on same path
        for(int v: adj[u])
        {
            if(vis[v] == 2)
                return true;
            else if(vis[v] == 0 && dfs(V, adj, vis, v) == true)
                return true;
        }
        
        vis[u] = 1;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
                if(dfs(V, adj, vis, i) == true)
                    return true;
        }
        
        return false;
    }
};