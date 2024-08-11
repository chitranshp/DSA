// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

/*
If there are n components in a graph, we will require n - 1 edges to connect all of them and make a single connected component or connected graph.
Steps:
1. Find number of connected Components. (Disjoint set or DFS/BFS can be used)
2. Find number of extra edges so that we know how many edges we can remove and use it elsewhere.
3. Check if extra edges >= required edges to make graph connected.

TC - O(E * α(V)) or O(E)
SC - O(v)
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

    int findNumOfConnectedComponents()
    {
        int numComponents = 0;
        for(int i = 0; i < parent.size(); i++)
            if(parent[i] == i)
                numComponents++;

        return numComponents;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int reqEdges = 0, totalEdges = connections.size();
        
        int extraEdges = 0; 
        for(vector<int> &connection: connections)
        {
            int u = connection[0];
            int v = connection[1];

            if(ds.findParent(u) != ds.findParent(v))
            {
                ds.unionBySize(u, v);
            }
            else        // Edge/connection is connecting a part of graph which is already connected or part of one component/set.
            {  
                extraEdges++;
            }
        }

        reqEdges = ds.findNumOfConnectedComponents() - 1;  
        return reqEdges <= extraEdges? reqEdges: -1;      
    }
};
