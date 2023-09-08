// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

/* Using topographical sort(This is a type of BFS with extra steps for indegree)
Given, a graph is directed. Then, a topographical sort can only be geneated if and only if, it is acyclic also. 
So, for detecting whether a directed graph is cyclic or not, we can use topographical sort algorithm. In case it is cyclic, kahn's algorithm will fail to find the topo sort.
If at the end, the size of output vector containing the sorted list of nodes is not equal to the number of vertices, then we can say that it is having cycles.

Note: We are only concerned about the size of topological sort vector, not it's actual order or contents. Instead of storing each node, we can just use one variable and keep the track of count.

TC - O(V + E) + O(2V)
SC - O(V)
*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int inDegree[V] = {0}, cnt = 0;
        queue<int> q;
        vector<int> topo;
        
        for(int i = 0; i < V; i++)
            for(int it: adj[i])
                inDegree[it]++;
                
        for(int i = 0; i < V; i++)
            if(inDegree[i] == 0)
                q.push(i);
                
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            // topo.push_back(node);
            
            for(int &it: adj[node])
            {
                if(--inDegree[it] == 0)
                    q.push(it);
            }
        }
        
        // If topographical sort is possible, then that means it is a DAG i.e. no cycle detected else cycle is present.
        return (cnt == V)? false: true;
        
    }
};
