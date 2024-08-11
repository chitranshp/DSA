// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
/*
Greedy algorithm: 
*/


class DisjointSet 
{
    private:
    vector<int> parent, size;
    
    public:
    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int findParent(int x)
    {
        if(parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
    }
    
    void unionBySize(int u, int v)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);
        
        if(parentU == parentV)
            return;
            
        if(size[parentU] < size[parentV])
        {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else if(size[parentU] >= size[parentV])
        {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
        
        return;
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DisjointSet ds(V);
        int mstWt = 0;
        vector<pair<int, pair<int, int>>> edges;     // wt, u, v
        
        // O(V + E)
        for(int i = 0; i < V; i++)      // Making list of edges
        {
            // Both (1, 5) & (5, 1) will be pushed to edges list. Although they represent one and same edge as graph is undirected.
            // Although disjoint set, can handle this by default.
            for(vector<int> &it: adj[i])
              if(i < it[0])       // (1 < 5), will be processed first time only    
                edges.push_back({it[1], {i, it[0]}});       
            
        }
        
        //O(ElogE)
        sort(edges.begin(), edges.end()); // sorting to get edges in ascending order
        
        // At max V - 1 union operations to form MST, O(E alpha(V)) can be taken as O(E)
        for(int i = 0; i < edges.size(); i++) // O(E)
        {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int wt = edges[i].first;
            
            // If both endpoints of vertices do not belong to same forest i.e. dont form a cycle.
            if(ds.findParent(u) != ds.findParent(v))
            {
                ds.unionBySize(u, v);
                mstWt += wt;
            }
        }
        
        return mstWt;
    }
};
