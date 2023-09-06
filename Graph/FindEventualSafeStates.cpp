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

        // If for all v adjacent to u, none of them are part of a cycle or leading into a cycle
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