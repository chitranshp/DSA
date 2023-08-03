// https://leetcode.com/problems/is-graph-bipartite/

/*
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
Note:
1. A bipartite graph is 2-colorable(Chromatic number <= 2).
2. A graph containing odd length cycle is not bipartite.  (Even length cycle does not necessarily mean bipartite)
*/

/*
Approach 1: Using BFS(Brute force)
Start with a empty color array which will act both as visited array and for storing colors. '-1' will mean node is unvisited and other value say '1' or '0' means node is visited and having that color.
We will try to color the graph using atmost 2 colors. For every node, we will assign all it's immidiate neighbour nodes with opposite color as the parent. If we found any visited node which has same color as it's immidiate neighbour , it's not bipartite.
And if we are able to successfully color the entire graph using 2 colors, then it is bipartite.(No two adjacent nodes have the same color)

Space Complexity - O(2V) Both for queue and color vector.
Time Complexity -  O(V + 2E) As graph is undirected, we are exploring all vertices and across all adjacent nodes.
*/

class Solution {
public:
    bool check(vector<vector<int>> &graph, vector<int> &color, int source)
    {
        queue<int> q;
        color[source] = 0;
        q.push(source);

        while(q.empty() == false)
        {
            int node = q.front();
            q.pop();

            for(int i : graph[node])
            {
                if(color[i] == -1)
                {
                    q.push(i);
                    color[i] = !color[node];
                }
                else if(color[i] == color[node])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size(), n = graph[0].size();
        vector<int> color(m, -1);

        // It is not given that the graph is connected.
        for(int i = 0; i < m; i++)      
        {
            if(color[i] == -1)          // This step is important. We won't try to fill a vertex with color if it is already filled in previous iteration.
                if(check(graph, color, i) == false)
                    return false;
        }

        return true;
    }
};