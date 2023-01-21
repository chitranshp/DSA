// https://leetcode.com/problems/flower-planting-with-no-adjacent/submissions/

//TODO GREEDY APPROACH
class Solution {
public:
    void creategraph(vector<vector<int>> &paths, vector<vector<int>> &graph) 
    {
        for(auto &e: paths)
        {
            graph[e[0] - 1].push_back(e[1] - 1);        //For 0-based indexing
            graph[e[1] - 1].push_back(e[0] - 1);
        }
    }

    bool isSafe(int& node, int& c, vector<vector<int>> &graph, vector<int> &flower) //O(n) for worst case, when every vertex is connected to one
    {
        for(auto &v: graph[node])
            if(flower[v] == c)
                return false;

        return true;
    }

    bool planting(int node, vector<vector<int>> &graph, vector<int> &flower) //(N^m) or O(N ^ 4) for this 
    {
        if(node == graph.size())
            return true;

        for(int c = 1; c < 5; c++)                  //4 is the Max. no of flower allowed
        {
            if(isSafe(node, c, graph, flower))
            {
                flower[node] = c;
                if(planting(node + 1, graph, flower) == true)
                    return true;
                else
                    flower[node] = 0;
            }
        }

        return false;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) 
    {
        vector<vector<int>> graph(n);
        vector<int> flower(n, 0);

        creategraph(paths, graph);
        planting(0, graph, flower);

        return flower;
    }
};
