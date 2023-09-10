// https://leetcode.com/problems/find-eventual-safe-states/submissions/

// O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity. 
// SC ~ O(3V) + O(V)

class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& vis, vector<int> &pathvis)
    {
        vis[u] = 1;
        pathvis[u] = 1;

        for(int v: graph[u])
        {
            /*
                If any vertex adjacent to u, is part of a loop or will lead to a loop, this block will return true with pathvis set to 1 for those vertices
            */

            if(vis[v] == 0)
            {
                if(dfs(v, graph, vis, pathvis) == true)
                {
                    //pathvis[v] = 1;
                    return true;
                }
            }
            else if(vis[v] == 1 && pathvis[v] != 0)
            {
                //pathvis[v] = 1;
                return true;
            }
        }

        // If FOR ALL v adjacent to u, none of them are part of a cycle or leading into a cycle
        // Reset pathvis[u] as 0. This vertex is safe node as it is not leading to a loop or part of it.
        pathvis[u] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> vis(n, 0), pathvis(n, 0);
        vector<int> safenodes;
        
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
                dfs(i, graph, vis, pathvis);
        }

        // As we need the output in ascending order.
        for(int i = 0; i < n; i++)
            if(pathvis[i] == 0)
                safenodes.push_back(i);

        return safenodes;
    }
};

/*
Approach2: Topological Sort(BFS)
We are looking for safe states i.e. terminal nodes and those nodes through which we can only reach terminal nodes. Terminal nodes have a outdegree of 0.
So, basically we are looking for nodes having outdegree 0 and other nodes which are connected to these nodes as they may or may not be safe states. But nodes having outdegree 0 are guarranteed to be safe state.

So, we will reverse every edge in the graph. This will make each node having outdegree 0 to a node having indegree 0. And then, we will use these nodes as starting point for our topological sort which will in turn give us all the nodes which can be reached from them without going through a cycle. And, any nodes which are part of a cycle or leading to a cylce will be skipped as they will still have indegree > 0.

TC - O(V+E)+O(V + E) + O(2V) + O(VlogV)
SC - O(3V) + O(V + E)
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        queue<int> q;
        vector<int> safeNodes, indegree(n, 0);

        for(int i = 0; i < graph.size(); i++)
            for(int &it: graph[i])
                revGraph[it].push_back(i);

        for(int i = 0; i < n; i++)
            for(int &it: revGraph[i])
                indegree[it]++;

        for(int i = 0; i < n; i++)
            if(indegree[i] == 0)
                q.push(i);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(int &it: revGraph[node])
            {
                if(--indegree[it] == 0)
                    q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};