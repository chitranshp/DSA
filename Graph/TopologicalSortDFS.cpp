// https://practice.geeksforgeeks.org/problems/topological-sort/1

/*
Topological sort is a linear ordering of the vertices (nodes) in a directed acyclic graph (DAG) such that for every directed edge (u, v), vertex u comes before vertex v in the ordering.
There can be more than 1 order which satisfies the properties of topological sort. This approach gives one of them.

DFS
TC - O(V) + O(V + E)
SC - O(2V) + O(V)
*/

class Solution
{
	public:
	void dfs(int u, vector<int> adj[], vector<int> &vis, stack<int> &st) 
	{
	    vis[u] = 1;
	    for(int v: adj[u])
	    {
	        if(vis[v] == 0)
	            dfs(v, adj, vis, st);
	    }
	    
	    st.push(u);         // If there are no unexplored adjacent nodes left, return and BEFORE returning push the current node to stack.
	    return;
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> arr, vis(V, 0);
	    stack<int> st;
	    
	    for(int i = 0; i < V; i++)
	        if(vis[i] == 0)
	            dfs(i, adj, vis, st);
	            
	    while(!st.empty())
	    {
	        arr.push_back(st.top());
	        st.pop();
	    }
	   
	    return arr;
	}
};