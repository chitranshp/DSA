// https://leetcode.com/problems/largest-local-values-in-a-matrix
// TC - O(9 * (n - 2) * (n - 2)) 
// SC - O(n - 2)^2

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int> (n - 2, 0));

        for(int i = 0; i < n - 2; i++) {
            for(int j= 0; j < n - 2; j++) {
                for(int i1 = i; i1 < i + 3; i1 ++) {
                    for(int j1 = j; j1 < j + 3; j1++) {
                        res[i][j] = max(res[i][j], grid[i1][j1]);
                    }
                }
            }
        }

        return res;
    }
};
