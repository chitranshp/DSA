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

/*
DFS - Cycle Detection in DAG + Topological sort using DFS

TC - O(V + E) + O(V)
SC - O(3V) + O(V + E)
*/

class Solution {
public:
    vector<vector<int>> buildGraph(int &nC, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(nC);
        for(auto &coursePair: prerequisites)
            graph[coursePair[1]].push_back(coursePair[0]);

        return graph;
    }

    bool dfs(int &u, vector<vector<int>> &graph, vector<int> &vis, stack<int> &courseStack)
    {
        vis[u] = 2;
        
        for(int v: graph[u])
        {
            if(vis[v] == 0)
            {
                if(dfs(v, graph, vis, courseStack) == false)
                    return false;
            }
            else if(vis[v] == 2)
                return false;
        }

        vis[u] = 1;
        courseStack.push(u);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph;
        vector<int> vis(numCourses, 0), courseSeq;
        stack<int> st;

        graph = buildGraph(numCourses, prerequisites);

        for(int i = 0; i < numCourses; i++)
            if(vis[i] == 0)
                if(dfs(i, graph, vis, st) == false)
                    return {};

        while(!st.empty())
        {
            courseSeq.push_back(st.top());
            st.pop();
        }

        return courseSeq;
    }
};