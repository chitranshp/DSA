// https://leetcode.com/problems/course-schedule-ii/

/*
Same logic as CourseSchedule-I, except here we need to print the order of courses. 
Using topological sort - Kahn's algorithm

TC - O(V + E) + O(2V)
SC - O(V + E) + O(2V) We are building the graph as well
*/

class Solution {
public:
    vector<vector<int>> buildGraph(int &numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for(auto &coursePair: prerequisites)
            graph[coursePair[1]].push_back(coursePair[0]);

        return graph;
    }

    vector<int> calcInDegree(int numCourses, vector<vector<int>> &graph)
    {
        vector<int> inDegree(numCourses, 0);

        for(auto &vec: graph)
            for(int &it: vec)
                inDegree[it]++;

        return inDegree;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph;
        vector<int> courseSeq, inDegree;
        queue<int> q;

        graph = buildGraph(numCourses, prerequisites);
        inDegree = calcInDegree(numCourses, graph);

        for(int i = 0; i < numCourses; i++)
            if(inDegree[i] == 0)
                q.push(i);    

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            courseSeq.push_back(node);

            for(int &it: graph[node])
            {
                if(--inDegree[it] == 0)
                    q.push(it);
            }
        }

        if(courseSeq.size() != numCourses)
            return {};

        return courseSeq;
    }
};