// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

/*
All pair shortest path algorithm - Works with negative cycles also. (Bottom up dynamic programming)

Note: 
1. Case k = 0, means either there is a direct edge between i & j or i and j are not connected.
2. Benefits over dijkstra, handles negative cycles also
3. But, if no negative cycles are present, dijkstra offers better time complexity O(VElogV), 
   if we apply dijkstra over every nodes.

TC - O(N ^ 3)
SC - O(N ^ 2)
*/

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < n; j++)
	        {
	            if(matrix[i][j] == -1)
	            {
	                matrix[i][j] = 1e9;
	            }
	        }
	    }
	    
	    for(int k = 0; k < n; k++)
	    {
	        for(int i = 0; i < n; i++)
	        {
	            for(int j = 0; j < n; j++)
	            {
	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    
	    for(int i = 0; i < n; i++)
	    {
	        if(matrix[i][i] <= -1)
	        {
	            // Negative cyle exists.
	        }
	        
	    }
	    
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < n; j++)
	        {
	            if(matrix[i][j] == 1e9)
	            {
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};
