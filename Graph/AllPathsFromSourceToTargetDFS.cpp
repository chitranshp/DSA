// https://leetcode.com/problems/all-paths-from-source-to-target/


// No of paths = O(2^(n - 2)) as every vertex between source and target may be or may not be in path. Total time complexity will be O(E + V*(2 ^ (V - 2)))
// Refer https://math.stackexchange.com/questions/284700/maximum-number-of-path-for-acyclic-graph-with-start-and-end-node/3961816#3961816
//ToDo - Topological Sort version

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& currpath, int curr)
    {
        if(curr == graph.size() - 1)
        {
            paths.push_back(currpath);      //If path leads to target, store it.
            return;
        }
        /*
        else if(curr == 0)
            currpath.push_back(curr);       //For 0th node, we can add it here or in the parent call.
        */

        for(int node : graph[curr])
        {                                   //Since graph is guarranted to be DAG. Therefore, not checking whether it is visited or not. And also because there might be a path going through a visited node.
            currpath.push_back(node);       //Add current node to path.
            dfs(graph, paths, currpath, node);
            currpath.pop_back();            //Backtrack ie remove current node from path.
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<int> currpath;
        vector<vector<int>> paths;

        currpath.push_back(0);              //Adding 0th node in path. Source will always be in path and need not be removed/backtracked.
        dfs(graph, paths, currpath, 0);
        return paths;  
    }
};
