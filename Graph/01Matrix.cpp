// https://leetcode.com/problems/01-matrix/description/

/*
TC - O(m * n)
SC - O(m * n) for visited array, queue and output vector.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size(), offsets[] = {0, 1, 0, -1, 0};
        vector<vector<int>> dist(m, vector<int> (n, 0)); 
        vector<vector<int>> vis(m, vector<int> (n, 0)); 
        queue<pair<pair<int, int>, int>> q;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // If cell has value 0, push it to queue and mark it as visited. We will treat each of them as source of our BFS
                // And using BFS, if we are able to reach a cell 1, the path used is guarranteed to be the smallest one. We will store it in our ouput vector
                if(mat[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push(make_pair(make_pair(i, j), 0));  // Distance of cell having value 0 to cells with 0 will be 0.
                }
                /*
                Mark unvisited
                else
                    vis[i][j] = 0;
                */
            }
        }

        // From each cell having 0, we will explore in  directions and see if are reaching any cell with 1. For each next level of exploration, we will increment the steps by 1.
        while(!q.empty())
        {
            int r = q.front().first.first, c = q.front().first.second;
            int step = q.front().second;
            dist[r][c] = step;      //For initial values(mat[i][j] = 0), this will be set to 0.
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int nr = r + offsets[k], nc = c + offsets[k + 1];

                // Cell must be unvisited and will be containing 1 then push it into queue and increase the number of steps by 1. 
                // Initially q will contain all 0's. From them, if we are reaching any cell with 1 that means from 1 we can reach 0 in step + 1.
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0)      // For all cell with 0's, vis will be already set to 1.
                {
                    vis[nr][nc] = 1;
                    q.push(make_pair(make_pair(nr, nc), step + 1));
                }
            }            
        }
        

        return dist;
    }
};