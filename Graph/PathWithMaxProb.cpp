// https://leetcode.com/problems/path-with-maximum-probability/

/*
TC - O(2 ^ V) Due to pruning, the practical runtime should be around O(V + E) but theoretical or worst case TC will remain same. As each node can be part of multiple paths and will be explored for each path.
SC - O(V + E) + O(V) for graph and recursion stack maxPathProbpectively
*/

class Solution {
public:
    void dfsHelper(vector<vector<pair<int, double>>> &graph, int src, int &end_node, double currPathProb, double &maxPathProb, vector<int> &vis)
    {
        if(src == end_node)
        {
            maxPathProb = max(maxPathProb, currPathProb);
            return;
        }

        vis[src] = 1;   // If the same vertex is found down the line when the same path is explored, it will be skipped
        for(pair<int, double> &it: graph[src])
        {
            int v = it.first;
            double wt = it.second;
            if(vis[v] == 0 && currPathProb * wt >= maxPathProb)     // To prune recursion calls. And also helps in avoiding multiplication precision related errors in large graphs.
            {
                dfsHelper(graph, v, end_node, currPathProb * wt, maxPathProb, vis);
            }
        }

        // Here we have to explore multiple paths not just 1 path which lead to end node from start node. And find the path with max probability.
        // So, vis is maxPathProbet at the end of a call that means when all nodes through the currPathProbent node have been explored.
        // Therefore, if the currPathProbent node is part of another path through an unexplored vertex it can be explored.
        vis[src] = 0;       
        return;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        vector<int> vis(n, 0);

        int i = 0;
        for(vector<int> &edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back({v, succProb[i]});
            graph[v].push_back({u, succProb[i]});
            i++;
        }

        double maxPathProb = 0;
        dfsHelper(graph, start_node, end_node, 1.0, maxPathProb, vis);

        return maxPathProb;
    }
};
