// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

/* 
  To Do
  Add BFS and Disjoint union version
*/

//Iterative DFS
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int> visited(n,0);
        unordered_map<int, vector<int>> graph;
        stack<int> s;       

        for(auto p: edges)
        {
            graph[p[0]].push_back(p[1]);    //Since, graph is bidirectional. If there is a path between node a and node b, then it also means that there is a path between node b and node a
            graph[p[1]].push_back(p[0]);
        }
        
        s.push(source);
        visited[source] = 1;

        while(!s.empty())
        {
            auto node = s.top();
            s.pop();

            if(node == destination)
                return true;

            visited[node] = 1;
            for(auto x : graph[node])
            {
                if(!visited[x])
                    s.push(x);
            }
        }

        return false;
    }
};
