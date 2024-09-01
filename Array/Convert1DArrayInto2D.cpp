// https://leetcode.com/problems/convert-1d-array-into-2d-array

/*
TC - O(m * n)
SC - O(m * n)
*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        long expectedElements = m * n;
        if(expectedElements != original.size())
            return {};

        vector<vector<int>> res(m, vector<int> (n, 0));
        int idx = 0;

        for(int i = 0; i < m; i++)
        {    
            for(int j = 0; j < n; j++)
            {
                res[i][j] = original[idx++];
            }
        }

        return res;
    }
};
