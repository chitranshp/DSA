// https://leetcode.com/problems/find-the-town-judge/submissions/883890840/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        if(trust.size() == 0 && n == 1)
            return 1;
            
        vector<int> degree(n + 1, 0);

        for(int i = 0; i < trust.size(); i++)
        {
            degree[trust[i][0]]--;
            degree[trust[i][1]]++;
        }

        for(int i = 0; i < degree.size(); i++)
            if(degree[i] == n - 1)
                return i;

        return -1;
    }
};

/*
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        if(trust.size() == 0 && n == 1)
            return 1;
        vector<int> indegree(n + 1, 0);     //counts the no of nodes that trusts a given node
        vector<int> outdegree(n + 1, 0);    //counts the no of nodes that a node trusts.

        for(int i = 0; i < trust.size(); i++)
        {
            indegree[trust[i][1]]++;
            outdegree[trust[i][0]]++;
        }

        for(int i = 0; i < indegree.size(); i++)
            if(indegree[i] == n - 1 && outdegree[i] == 0)
                return i;

        return -1;
    }
};

*/
