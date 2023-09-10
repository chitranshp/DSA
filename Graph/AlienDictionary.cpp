// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

// TC - O(N * len) + O(K + E) where len -> length upto the index where first inequality occurs
// SC - O(K + E) + O(3K)

/*
    Note:
    Conditions where the given order/dictionary is not correct
     Case1: s1: abc and s2: abcd  
     Here, if everything is matching AND the larger string is before the shorter string. Then the order is wrong.
     This dictionary is not possible/correct

     Case2: Cyclic dependency for ex. a->b->. 
     This dictionary is also not possible a cannot be both before 'b' and after it.
    
    We can create test cases/checks for these 2 conditions if the dictionary is not guarranted to be correct.
*/

class Solution{
    public:
    string findOrder(string dict[], int N, int K) 
    {
        vector<vector<int>> graph(K);
        queue<int> q;
        vector<int> indegree(K, 0);
        string res = "";
        int j = 0;
        
        // Examine strings 2 at a time to find the alien order and build a directed graph representing the order.
        for(int i = 0; i < N - 1; i++)
        {
            j = 0;                  // Reset j for next iteration
            while(j < min(dict[i].size(), dict[i + 1].size()))
            {
                if(dict[i][j] != dict[i + 1][j])            // At first inequality
                {
                    int u = dict[i][j] - 'a', v = dict[i + 1][j] - 'a';
                    graph[u].push_back(v);
                    break;                                  // Move to next pair of strings
                }
                
                j++;
            }
        }
            
        // Perform toplogical sort on the directed acyclic graph built and store the sorted order in a string(res)
        // Due to the constraint of this being a dictionary, this graph will always be acyclic.
        for(int i = 0; i < K; i++)
            for(int &it: graph[i])
                indegree[it]++;


        for(int i = 0; i < K; i++)
            if(indegree[i] == 0)
                q.push(i);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node + 'a');

            for(int &it: graph[node])
                if(--indegree[it] == 0)
                    q.push(it);
        }

        return res;
    }
