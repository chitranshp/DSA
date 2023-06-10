// https://leetcode.com/problems/01-matrix/description/

/*
TC - O(m * n)
SC - O(m * n)
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int> (n, 1e6));  // Initial values must be max or maxlike.
        
        // First Pass: Calculate distance for top and left
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                    dist[i][j] = 0;
                else
                {
                    if(j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                    if(i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
            }
        }

        // Second Pass: Calculate distance for bottom and right
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(mat[i][j] == 0)
                    dist[i][j] = 0;
                else
                {
                    if(j < n - 1)
                        dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                    if(i < m - 1)
                        dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
            }
        }

        return dist;
    }
};