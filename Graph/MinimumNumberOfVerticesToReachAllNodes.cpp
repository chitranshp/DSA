// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

//TODO Topological sort approach

/*
Optimal Approach: We just need to find all those vertices whose indegree(number of incoming edges) is 0. 

If a vertex has no incoming edge, then it means there is no other option but to include it in our set, if we want to reach it.
Remaining all other vertices which has a indegree more than 0, we don't need to include them as we would have included one of the vertices from which there is a incoming edge to this one.

TC - O(E)
SC - O(V)
*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> res, seen(n, 0);
        
        for(auto &edge : edges) 
            seen[edge[1]] = 1;

        for(int i = 0; i < n; i++)
        {
            if(seen[i] == 0)
                res.push_back(i);
        }

        return res;
    }
};