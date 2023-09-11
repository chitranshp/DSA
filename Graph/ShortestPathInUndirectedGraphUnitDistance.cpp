// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

/*
According to intuition, we will calculate the shortest path in an undirected graph having unit weights by using the Breadth First Search. BFS is a traversal technique where we visit the nodes level-wise, i.e., it visits the same level nodes simultaneously, and then moves to the next level.

TC - O(E) for adding edges to adjacency list + O(V + 2E) as the graph is undirected
SC - O(V + 2E) + O(2V)
*/

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
    {
        vector<vector<int>> graph(N);   // N vertices
        vector<int> dist(N, 1e9);
        queue<int> q;
        
        // M edges
        for(int i = 0; i < M; i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        dist[src] = 0;
        q.push(src);
        while(!q.empty()) 
        {
            int u = q.front();
            q.pop();
            
            for(int &v: graph[u])
            {
                if(dist[v] > 1 + dist[u])       // If a node appears again after being visited, this condition will evaluate to false, as BFS traverses level wise and the shortest path has already been taken in first visit. Therefore, that node wont be added in queue again.
                {
                    dist[v] = 1 + dist[u];
                    q.push(v);
                }
            }
        }
        
        for(int i = 0; i < N; i++)
            if(dist[i] >= 1e9)
                dist[i] = -1;
        
        
        return dist;
    }
};
