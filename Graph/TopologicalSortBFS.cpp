// https://www.youtube.com/watch?v=73sneFXuTEg&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=22

/* 
    Kahn's algorithm 
    1. Calculate the indegree for all the nodes.
    2. Push all the nodes having indegree 0 into a queue. Initially, there will be always at least a single node whose indegree is 0. So, we will push the node(s) with indegree 0 into the queue.
    3. Then, we will pop a node from the queue including the node in our answer array, and for all its adjacent nodes, we will decrease the indegree of that node by one. For example, if node u that has been popped out from the queue has an edge towards node v(u->v), we will decrease indegree[v] by 1.
    4. After that, if for any node the indegree becomes 0, we will push that node again into the queue.
    We will repeat steps 3 and 4 until the queue is completely empty. Finally, completing the BFS we will get the linear ordering of the nodes in the answer array.

    TC - O(V) + O(V) + O(V + E) (BFS algo with two additional steps related to indegree each of O(V))
    SC - O(V) + O(V)
*/


class Solution
{
	public:
	void calcInDeg(int &V, vector<int> adj[], vector<int> &inDeg) 
	{
	    for(int i = 0; i < V; i++)
	    {
	        for(int j = 0; j < adj[i].size(); j++)
	        {
	            inDeg[j]++;
	        }
	    }
	    
	    return;
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indegree[V] = {0};
	    vector<int> topo;
	    queue<int> q;
	    
	    for(int i = 0; i < V; i++)
	        for(int j = 0; j < adj[i].size(); j++)          // for(int j : adj[i])
	            indegree[adj[i][j]]++;                              // indegree[j]++;
	            
	    for(int i = 0; i < V; i++)
	        if(indegree[i] == 0)
	            q.push(i);
	            
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it: adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0)
	                q.push(it);
	        }
	    }
	    
	    return topo;
	}
};