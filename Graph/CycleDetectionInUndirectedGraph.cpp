// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

/*
Approach 1: Using BFS
TC - O(V + 2E) as we are using adjacency list here and graph is undirected
SC - O(V) + O(V)
*/

class Solution {
  private:
    bool detectCycle(int src, vector<int> adj[], int vis[])
    {
        queue<pair<int, int>> toVisit;
        
        // -1 is to denote that no parent node exists for this node
        toVisit.push(make_pair(src, -1));
        vis[src] = 1;
                
        while(!toVisit.empty())
        {
            int node = toVisit.front().first;
            int parent = toVisit.front().second;
            toVisit.pop();
                    
            for(int adjacentNode : adj[node])
            {
                // Since, the graph is undirected, For edge (u, v), u will be in the adjacency list of v as wells as v will be in the adjacence list of u.
                // So, whenever we find that a node is visited, we will check whether is it it's immediate parent, if not we can safely say that it is a cycle
                if(vis[adjacentNode] == 1 && adjacentNode != parent)
                    return true;
                else if(vis[adjacentNode] == 0)
                {
                    vis[adjacentNode] = 1;
                    toVisit.push(make_pair(adjacentNode, node));
                }
                else
                    continue;
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        int vis[V] = {0};
        
        // The graph is not guarranteed to be connected. It can be disconnected also. Therfore we are using BFT
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                if(detectCycle(i, adj, vis) == true)
                    return 1;
            }
        }
        
        return 0;
    }
};

/*
Approach 2: Using Iterative DFS
TC - O(V + 2E)
SC - O(V)
*/

class Solution {
  private:
    bool detectCycle(int src, vector<int> adj[], int vis[])
    {
        stack<pair<int, int>> toVisit;
        
        // -1 is to denote that no parent node exists for this node
        toVisit.push(make_pair(src, -1));
        vis[src] = 1;
                
        while(!toVisit.empty())
        {
            int node = toVisit.top().first;
            int parent = toVisit.top().second;
            toVisit.pop();
                    
            for(int adjacentNode : adj[node])
            {
                // Since, the graph is undirected, For edge (u, v), u will be in the adjacency list of v as wells as v will be in the adjacence list of u.
                // So, whenever we find that a node is visited, we will check whether is it it's immediate parent, if not we can safely say that it is a cycle
                if(vis[adjacentNode] == 1 && adjacentNode != parent)
                    return true;
                else if(vis[adjacentNode] == 0)
                {
                    vis[adjacentNode] = 1;
                    toVisit.push(make_pair(adjacentNode, node));
                }
                else
                    continue;
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        int vis[V] = {0};
        
        // The graph is not guarranteed to be connected. It can be disconnected also. Therfore we are using BFT
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                if(detectCycle(i, adj, vis) == true)
                    return 1;
            }
        }
        
        return 0;
    }
};

/*
Approach 3: Using Recursive DFS
TC - O(V + E)
SC - O(V) + O(V) Visited array + recursion stack space
*/

class Solution {
  private:
    bool detectCycle(int node, vector<int> adj[], int vis[], int parent)
    {
        vis[node] = 1;
                    
        for(int adjacentNode : adj[node])
        {
            if(vis[adjacentNode] == 1 && adjacentNode != parent)
                return true;
            else if(vis[adjacentNode] == 0)
            {
                vis[adjacentNode] = 1;
                
                // This will return true, if cycle is point at any vertex node. But in case, if for any one vertex 
                // cycle is not found, it will return false. In that case, we don't want to return false across all parent calls in recursion tree.
                // We will want it to continue checking across whole graph
                if(detectCycle(adjacentNode, adj, vis, node) == true)
                    return true;
                
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        int vis[V] = {0};
        
        // The graph is not guarranteed to be connected. It can be disconnected also. Therfore we are using BFT
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                if(detectCycle(i, adj, vis, -1) == true)
                    return true;
                // else -> continue checking other nodes
            }
        }
        
        return false;
    }
};
