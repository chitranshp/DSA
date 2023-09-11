// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

/*
    Finding the shortest path to a vertex is easy if you already know the shortest paths to all the vertices that can precede it. Processing the vertices in topological order ensures that by the time you get to a vertex, you’ve already processed all the vertices that can precede it which reduces the computation time significantly. 
    In this approach, we traverse the nodes sequentially according to their reachability from the source and is more efficient compared to other shortest path algorithms. Another efficient approach can be DP.

    Note: For cyclic graphs, this is not applicable as topological sort cannot be performed. In that case, we will have to use djikstra or some other algorithm.    
    
    1. Perform topological sort(either bfs or dfs)
    2. Update distance[source] = 0 and keep infinity for rest.
    3. Based on order recieved by topological sort, start relaxing a vertex and it's immediate adjacent nodes,
       untill all vertices are exhausted. (For every node that comes out of the stack which contains our topo sort, we can traverse for all its adjacent nodes, and relax them. )
       
    TC - O(V + E) + O(V + E)
    SC - O(V + E) for building graph + O(2V)
*/

class Solution {
  public:
     vector<int> topoSort(vector<vector<pair<int, int>>> &graph)
     {
         int n = graph.size();
         vector<int> topo;
         int indegree[n] = {0};
         queue<int> q;
         
         for(int i = 0; i < n; i++)
         {
             for(auto &p: graph[i])
             {
                 indegree[p.first]++;
             }
         }
         
         for(int i = 0; i < n; i++)
            if(indegree[i] == 0)
                q.push(i);
                
                
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto &it: graph[node])
            {
                if(--indegree[it.first] == 0)
                    q.push(it.first);
            }
        }
        
        return topo;
     }
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
     {
        vector<vector<pair<int, int>>> graph(N);
        vector<int> topo, dist(N, 1e9);
        int source = 0;
        
        for(vector<int> &e: edges)
        {
            graph[e[0]].push_back(make_pair(e[1], e[2]));
        }
        
        topo = topoSort(graph);
        
        dist[source] = 0;
        
        // Taking vertices based on topological order using topo vector.
        for(int i = 0; i < N; i++)
        {
            int u = topo[i];
            for(auto &it: graph[u])
            {
                int v = it.first, wt = it.second;
                
                if(dist[v] > dist[u] + wt)
                    dist[v] = dist[u] + wt;
            }
        }
        
        for(int i = 0; i < N; i++)
            if(dist[i] >= 1e9)
                dist[i] = -1;
        
        return dist;
    }
};