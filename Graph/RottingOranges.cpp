// https://leetcode.com/problems/rotting-oranges/

/*
TC - O(m * n) It will go through all nodes atleast once.
SC - O(m * n) For the visited array and queue.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // Each element of queue is a pair<pair<row, col>, timeOfRotting>
        queue<pair<pair<int, int>, int>> rotten;
        int n = grid.size(), m = grid[0].size(), offsets[] = {0, 1, 0, -1, 0};
        int total_time = 0;
        
        // vis array will only track whether a orange is alreayd rotten(2) or (0).
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int cntFresh = 0, cntSpoiled = 0;

        // Initially we will push all the rotten oranges in a queue with time as 0.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    rotten.push(make_pair(make_pair(i, j), 0));     // time is 0 as it was already rotten at beginning
                    vis[i][j] = 2;          //Mark it as already rotten in visited array. So, that there is no chance of revisiting
                }   

                if(grid[i][j] == 1)
                    cntFresh++;             //To track the initial number of fresh oranges
            }
        }

        // We need the minimum number of minutes it will take to rot all reachable FRESH oranges. So, we need a kind of shortest path and we can rot oranges level by level i.e. First, oranges that are 1 unit away will rot then for 2 unit and so on.
        // For this, we can use BFS as it goes level by level and ends up with shortest path.
        // BFS will always give the shortest time to travel. (If we have used DFS, we will have to add a separate logic to track the minimum. With BFS, we are guarranteed to find the minimum)
        while(!rotten.empty())
        {
            int r = rotten.front().first.first, c = rotten.front().first.second;
            int t = rotten.front().second;
            rotten.pop();

            //All fresh oranges will go through the rotten queue once.
            // It will go through all pairs in rotten queue. And will store the max time of rotting for any fresh orange in that queue.
            total_time = max(t, total_time);

            for(int k = 0; k < 4; k++)
            {
                int nr = r + offsets[k], nc = c + offsets[k + 1];

                // Orange is not rotten by any other orange AND is a FRESH orange(We don't want oranges which were originally rotten by themselves being considered again)
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] == 1)
                {
                    vis[nr][nc] = 2;    // Mark it as rotten
                    rotten.push(make_pair(make_pair(nr, nc), t + 1));
                    cntSpoiled++;
                }
            }
        }

        // If any fresh orange is left unspoiled
        if(cntFresh != cntSpoiled)
            return -1;

        return total_time;
    }
};
