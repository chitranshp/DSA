// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/submissions/876263013/

class Solution {
public:
    //The given data is in the form of edge pairs. Therefore, converting it into graph using adjacency list representation.
    void creategraph(vector<vector<int>>& edges, unordered_map<int, vector<int>>& graph)    //O(n) and SC O(V+E)
    {
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }

    /*
    We will use dfs to recursively travel each node and it's subtree to find whether it contains an apple or not. If it does not contain an apple  is AND also not an apple, we will return the cost as 0. Else, we will return the sum of that node + the sum of it's children.
    */
    int dfs(int node, unordered_map<int, vector<int>>& graph, vector<bool>& hasApple, vector<bool>& visited, int myCost)    //O(n)
    {
        if(visited[node] == true)
            return 0;

        visited[node] = true;

        int childrencost = 0;
        for(auto e: graph[node])
            childrencost += dfs(e, graph, hasApple, visited, 2);        //For each child node, the cost to travel from parent to child will be 2(1 for reaching child and 1 for travelling back). In this way, we will recursivley calculate the cost for all children of each node.

        /*
        If node does not have a apple and none of it's children also do not have a apple, we will won't travel that path or subtree. Therefore, returning the cost as 0.
        */
        if(childrencost == 0 && hasApple[node] == false)
            return 0;    

        //if (childrencost != 0 || hasApple[node] == true)
        return childrencost + myCost;   //If in case node has an apple or/and any of it's child has a apple. If it's children do not have an apple, then childrencost will be 0.
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        int cnt = 0, mycost = 0, source = 0;
        unordered_map<int, vector<int>> graph;
        creategraph(edges, graph);      //creating graph 
        vector<bool> visited(n, 0);

        return dfs(source, graph, hasApple, visited, mycost); // The cost for root node will be 0.
    }
};
