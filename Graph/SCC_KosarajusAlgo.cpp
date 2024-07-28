// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
// TC - O(V + E) + O(V + E) + O(V + E)
// SC - O(V + E) + O(V) + O(V)

/*
A strongly connected component of a directed graph G(V, E) is a maximal set of vertices C which is a subset of V such that for every pair
of vertices u and v in C, we have both u reachable from v and v reachable from u; that is, vertices u and v are reachable from each other.

                                                      SCC1 -> SCC2 -> SCC3 -> SCC4
1. The first step is to know, from which node we should start the DFS call. The nodes in the last SCC will finish first and will be stored in the beginning of the 
   vector. After the DFS gets completed for all the nodes, the vector will be storing all the nodes in the ascending sorted order of their finishing time.
                                                      
2. The second step is to make adjacent SCCs unreachable and to limit the DFS traversal in such a way, that in each DFS call, all the nodes of a particular SCC get 
   visited. 
                                                     SCC1 <- SCC2 <- SCC3 <- SCC4
3. The third step is to get the numbers of the SCCs. Because, if we start dfs call from a node in SCC4, we will again visit entire graph instead of one SCC.
   In this step, we can also store the nodes of each SCC if we want to do so.
  
  Note: The sorting of the nodes according to their finishing time is very important. By performing this step, we will get to know where we should start our DFS calls. 
  The top-most element of the stack will finish last and it will surely belong to the SCC1. So, the sorting step is important for the algorithm.
*/
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs1(vector<vector<int>>& adj, vector<int>& finishingOrder, vector<int>& vis, int u) 
	{
	    vis[u] = 1;
	    
	    for(int& v: adj[u]) 
	    {
	        if(vis[v] == 0)
	            dfs1(adj, finishingOrder, vis, v);
	    }
	    
	    finishingOrder.push_back(u);
	    return;
	}
	
	void dfs2(vector<vector<int>>& adjT, vector<int>& vis, int u)
	{
	    vis[u] = 1;
	    
	    for(int &v: adjT[u])
	    {
	        if(vis[v] == 0)
	            dfs2(adjT, vis, v);
	    }
	    
	    return;
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<vector<int>> adjT(V);
        vector<int> vis(V, 0), finishingOrder;
        int numComponents = 0;
        
        // DFS to find the finishing order of vertices
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                dfs1(adj, finishingOrder, vis, i);
            }
        }
        
        // Building Transform of the graph
        for(int u = 0; u < V; u++)
        {
            for(int &v: adj[u])
            {
                adjT[v].push_back(u);
            }
        }
        
        // Resetting vis for next dfs call.
        fill(vis.begin(), vis.end(), 0);
        
        // Calling dfs on transform graph by considering vertices based on decreasing finishing order
        while(!finishingOrder.empty())
        {
            int u = finishingOrder.back();    // We are taking values from back, instead of reversing vector. As we need nodes as per decreasing order of finishing time.
            finishingOrder.pop_back();
            
            if(vis[u] == 0)
            {
                dfs2(adjT, vis, u);
                numComponents++;
            }
        }
        
        return numComponents;      
    }
};
