// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

/*
TC - O(V + 2E) For a undirected graph, it will go through all vertices atmost once and edges twice
SC - O(V) (Stack + Output + visited array)
*/

class Solution {
  private:
    void dfs(int u, int vis[], vector<int> adj[], vector<int> &dfsOutput)
    {
        vis[u] = 1;
        dfsOutput.push_back(u);
        
        for(auto v: adj[u])
        {
            if(vis[v] == 0)
                dfs(v, vis, adj, dfsOutput);
        }
        
        return;
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        int vis[V] = {0};
        int source = 0;
        vector<int> dfsOutput;
        
        dfs(source, vis, adj, dfsOutput);
        return dfsOutput;
    }
};