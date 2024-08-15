// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

/*
1. We can say that a group of stones which share the same row or column are connected and think of them as connected component in a graph.
2. For such a connected component, we cannot remove all stones inside it. We will have to keep one stone as per problem statement.
3. For component 1, if there are n1 stones in it, we can remove n1 - 1 stones.
4. So, if total k components are present in the graph and let n1, n2, n3.... nk represent the number of stones in each component
   Then, we can say that:
   n1 + n2 + n3 +..... + nk = n
   Number of stones that we can remove:
   n1 - 1 + n2 - 1 + n3 - 1 +....+ nk - 1 
   = n - k

   So, to solve this we need to find the number of connected components, we can use either DFS/BFS traversal or Union find approach.
*/

/*
Approach1: DFS
Input is given in form of list of coordinates of stones, not graph. So, we will just iterate over the list of stones and for each stone, we will use dfs traversal to 
find all other stones which are connected to it. To find that, we will again iterate over the list of all stones and see which stones share the same row OR same column
to the first stone. To avoid revisiting allready visited stones, we will use a visited vector and mark each stone as visited after discovering it.

Due to visited array, the max stack height for recursion calls will be n(n stones). 
TC - O(n ^ 2)
SC - O(n) + O(n)
*/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &stones, vector<int> &vis)
    {
        int n = stones.size();

        for(int i = 0;  i < n; i++)
        {
            // If the stone is not visited and shares the same row or column
            if(vis[i] == 0 && (stones[i][0] == row || stones[i][1] == col))
            {
                vis[i] = 1;
                dfs(stones[i][0], stones[i][1], stones, vis);
            }
        }

        return;
    }

    /*
    Outer Loop: Iterates over each stone, so O(n).
    Inner Loop in helper Function: For each stone, the helper function checks all n stones to see if they share the same row or column, leading to O(n) time for each
    call to dfs.
    */
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vis(n, 0);

        int numComponents = 0;

        for(int i = 0; i < n; i++) // O(n)
        {
         if(vis[i] == 0)   
         {
            numComponents++;
            vis[i] = 1;
            dfs(stones[i][0], stones[i][1], stones, vis);    
         }
        }  
        
        // Total number of stones - number of connected components
        return  stones.size() - numComponents;
    }
};

/*
Approach 2: DFS on ajacency list
TC - O(n ^ 2)
SC - O(n ^ 2)

For adjacency list, in worst case when all stones share a same row/column. Each stone is connected to n - 1 stones. Therefore for each node there will be n - 1 connectinos
Total space complexity will be O(n * n)
*/

class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &adjList, vector<int> &vis)
    {
        vis[node] = 1;
        for(int &adjNode: adjList[node])
        {
            if(vis[adjNode] == 0)
            {
                dfs(adjNode, adjList, vis);
            }
        }

        return;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vis(n, 0);
        unordered_map<int, vector<int>> rowToStones, colToStones;
        unordered_map<int, vector<int>> adjList;

        // Here, each stone is mapped using it's index in stones vector as value, whereas x & y coordinate
        // serve as the keys
        for(int i = 0; i < n; i++)
        {
            int row = stones[i][0], col = stones[i][1];
            rowToStones[row].push_back(i);      // ith stone is in this row
            colToStones[col].push_back(i);
        }

        // We will use previous maps to map each index/stone in stones to other indexes which share the same row or column
        for(int i = 0; i < n; i++)
        {
            int row = stones[i][0], col = stones[i][1];
            // In worst, case all 'n' stones can be one row or in column, making the time complexity of this loop as O(n ^ 2)
            for(int stone: rowToStones[row])
                if(stone != i)
                    adjList[i].push_back(stone);

            for(int stone: colToStones[col])
                if(stone != i)
                    adjList[i].push_back(stone);
        }

        int numComponents = 0;
        // This will traverse the whole adjList which has TC O(V + E), where V = number of unique stones
        // But E is bounded by O(n ^ 2) max number of edges(Worst case, all stones are in same row/column). Then each stone is connected with n - 1 stones)
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)   
            {
                numComponents++;
                dfs(i, adjList, vis);    
            }
        } 
        
        // Total number of stones - number of connected components
        return  stones.size() - numComponents;
    }
};
