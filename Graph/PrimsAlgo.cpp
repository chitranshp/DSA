
/*
An MST in a graph is a subset of edges in graph that connect all the vertices together, without
any cycles and with minimum possible edge weight. Called a spanning tree as it is acyclic and
spans all vertices.
Total edges in a MST for a graph having n vertices -> n - 1

Note: A graph having only distinct edge weights will have only one Minimum spanning tree. 
      Whereas a graph having non-distinct weights multiple MST's can be possible.

      We need a triplet pq only, if we want to print the MST as we will need to track the parent also. If we only want to find the weight of MST, we can use
      pair<int, int> => wt, node

Total TC - O(ElogV + VlogV) -> O(ElogV) as in a graph generally E >> V
      SC - O(V) not considering the input
*/

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int vis[V] = {0};
        int wtMst = 0, lenMst = 0;
        
        pq.push({0, {0, -1}});  // wt, node, parent
        while(!pq.empty())  // O(V) - Refer, inner loop push operation
        {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();    // O(logV)
            
            if(vis[node] == 1)
              continue;
            
            vis[node] = 1;    
            // If we want to print the MST, we can store it in a vector here, (parent, node)
            if(parent != -1)
            {
              wtMst += wt;
              lenMst++;
            }
            else if(lenMst == V - 1)    // Not necessary, algorithm will still terminate regardless
              break;
            
            for(auto &it: adj[node])  // All edges in graph can be explored O(E))
            {
              int adjNode = it[0];
              if(vis[adjNode] == 0)
              {
                int edgeWt = it[1]; 
                // We are only pushing a node, if it's not visited(part of MST YET). Total V nodes will be pushed, all visited/cycle forming nodes will be skipped
                pq.push({edgeWt, {adjNode, node}});      // O(logV)
              }
            }            
        }
      
        return wtMst;
    }
};

// Approach 2

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int vis[V] = {0};
        int wtMst = 0, lenMst = 0;
        
        // wt, node
        pq.emplace(0, 0);
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(vis[node] == 1)
                continue;
            else if(lenMst > V - 1)
                break;
                
            wtMst += wt;
            vis[node] = 1;
            lenMst++;
            for(const vector<int> &it: adj[node])
            {
                int adjNode = it[0];
                int edgeWt = it[1];
                if(vis[adjNode] == 0)
                {
                    pq.emplace(edgeWt, adjNode);    
                }
            }
            
        }
        
        return wtMst;
    }
};
