// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

/*
Bellman-Ford algorithm returns a boolean value indicating whether or not there is a negative-weight cycle that is reachable from the source. If there is such a cycle, the algorithm indicates that no solution exists. If there is no such cycle, the algorithm produces the shortest paths and their weights. The algorithm relaxes edges, progressively decreasing an estimate :d on the weight of a shortest path from the source s to each vertex  2 V until it achieves the actual shortest-path weight. 

The algorithm returns TRUE if and only if the graph contains no negative-weight cycles that are reachable from the source.

TC - O(VE)
SC - O(V)
*/

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) 
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        // Relax V - 1 times. Because, the shortest path at max will contain V - 1 edges
        for(int i = 0; i < V - 1; i++)     // O(V)
        {
            for(vector<int> &edge: edges)  //O(E)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dist[u] + w < dist[v] && dist[u] != 1e8)    //Relax if u is not itself INFINITY.
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // One more iteration to relex all edges to detect negative cycle
        for(vector<int> &edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] + w < dist[v] && dist[u] != 1e8)      ////Relax if u is not itself INFINITY.
            {
                return {-1};
            }
        }
        
        return dist;
    }
};
