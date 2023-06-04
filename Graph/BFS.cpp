// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

/*
Graph is directed
TC - O(V + E) (If it was undirected, then O(V + 2E))
SC - O(3V) As O(V) for queue, vector and visited array. If we include input adj list also then O(V + E)
*/

/*
We can use this alorithm to print the shortest-path 
    The following procedure prints out the vertices on a shortest path from s to v,
    assuming that BFS has already computed a breadth-first tree:

    PRINT-PATH(G, s, v)
    1 if v == s
    2   print s
    3 elseif v:parent == NIL
    4   print “no path from” s “to” v “exists”
    5 else PRINT-PATH(G, s, v.parent)
    6   print v

    This procedure runs in time LINEAR TIME in the number of vertices in the path printed,
    since each recursive call is for a path one vertex shorter
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

/*
Approach 2: Similar to CLRS version. Contains additional parts to track edges(back, forward and mixed) along with parents and levels. Levels can further be used to find length of shortest path from source to any node and parents can be used to find that shortest path
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        // 0 -> Not visited(white) 1->seen but not visited(grey) 2->seen and visited(black)
        int vis[V] = {0};

        // We can also add a flag value say infinity and initialize the parent with it. And for any node, if after the completion of bfs parent[node] is equal to inf that means that node is not reachable from source
        int parent[V] = {-1};
        int level[V] = {0};     //It will indicate the length of shortest path to a node v from source node.
                                // For source node level will be 0.
                                // There can be multiple shortest paths. This gives ONE of those
        queue<int> q;
        vector<int> bfs;
        
        int source = 0;
        q.push(source);
        
        parent[source] = 0;
        level[source] = 0;
        vis[source] = 1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(int &it: adj[node])
            {
                if(vis[it] != 1 && vis[it] != 2)
                {
                    parent[it] = node;
                    level[it] = level[node] + 1;    //level[it] = level[parent[it]] + 1;
                    
                    q.push(it);
                    vis[it] = 1;
                }
            }
            
            vis[node] = 2;
        }
        
        return bfs;
    }
};