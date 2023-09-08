// https://leetcode.com/problems/course-schedule/description/

/*
We can convert the given schedule into a directed graph(as courses have a certain prerequisite and must be taken in that order only). The problem then turns into finding whether a cycle is forming in that graph or not.

If a cycle is formed, then that schedule is not possible.
*/

/*
Kahn's algorithm: BFS
TC - O(V) + O(V + E)
SC - O(2V)
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        int cnt = 0;

        // Can be refactored into buildGraph() function
        for(auto &vec: prerequisites)
            graph[vec[1]].push_back(vec[0]);

        // calcInDegree()
        for(int i = 0; i < numCourses; i++)
            for(auto it: graph[i])
                indegree[it]++;

        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;

            for(int &it: graph[node])
            {
                if(--indegree[it] == 0)
                    q.push(it);
            }
        }

        return cnt == numCourses;       // If true, no cycle found i.e. schedule is possible
    }
};

/*
DFS - Similar to Cycle detection using DFS

TC - O(V) + O(V + E)
SC - O(2V) + O(V + E)
*/

class Solution {
public:
    // This will return false, when a loop is detected i.e. whenver it encounters an adjacent node having vis as 2(meaning traversed on the same path previously)
    bool dfs(int &u, vector<vector<int>> &graph, vector<int> &vis) 
    {
        vis[u] = 2;     // 2 indicates that node was visited/inside the current recursion stack

        for(int &v: graph[u])
        {
            if(vis[v] == 0)
            {
                if(dfs(v, graph, vis) == false)
                    return false;
            }
            else if(vis[v] == 2)
                return false;
        }

        vis[u] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses);
        vector<int> vis(numCourses, 0);

        for(auto &vec: prerequisites)
            graph[vec[1]].push_back(vec[0]);

        for(int i = 0; i < numCourses; i++)
            if(vis[i] == 0)
                if(dfs(i, graph, vis) == false)
                    return false;

        return true;
    }
};