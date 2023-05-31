// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

/*
Graph is directed
TC - O(V + E) (If it was undirected, then O(V + 2E))
SC - O(3V) As O(V) for queue, vector and visited array. If we include input adj list also then O(V + E)
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        int vis[V] = {0};
        queue<int> q;
        vector<int> bfs;        //To store bfs ordering of graph
        
        vis[0] = 1;        
        q.push(0);

        while(q.empty() != true)
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(int &it : adj[node])
            {
                if(vis[it] != 1)
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return bfs;
    }
};