// https://leetcode.com/problems/first-completely-painted-row-or-column/description/

/*
TC - O(m*n + k) where k is the size of arr. In worst case k can be O(mn) 
TC - O(m*n) + O(m) + O(n)
*/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> rc;
        int m = mat.size(), n = mat[0].size();

        for(int i = 0; i < m; i++)      
        {
            for(int j = 0; j < n; j++)
            {
                rc[mat[i][j]] = {i, j};
            }
        }

        vector<int> row(m, 0), col(n, 0);
        for(int i = 0; i < arr.size(); i++)
        {
            int r = rc[arr[i]].first, c = rc[arr[i]].second;
            // For m = 2(rows) and n = 3 (columns), a row will have 3 cells whereas a column will have 2 cells
            // For a row to be painted, all columns in each will have to be painted and vice versa
            if(++row[r] == n || ++col[c] == m)
                return i;
        }

        return -1; //No such row or column
    }
};

/*
TC - O(k + mn + mn)
SC - O(k) where k is the size of arr
*/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> elementToIndex;
        for(int i = 0; i < arr.size(); i++)
            elementToIndex[arr[i]] = i;

        int rows = mat.size(), cols = mat[0].size();
        int earliestRowCompletion = INT_MAX;        // Stores the index of arr at which any of the row gets completely painted

        for(int i = 0; i < rows; i++)
        {
            int latestPaintIndex = INT_MIN;         // Last matrix cell of i'th row to get painted
            for(int j = 0; j < cols; j++)
            {
                latestPaintIndex = max(latestPaintIndex, elementToIndex[mat[i][j]]);
            }

            earliestRowCompletion = min(latestPaintIndex, earliestRowCompletion);
        }

        int earliestColCompletion = INT_MAX;        // Stores the index of arr at which any of the row gets completely painted
        for(int j = 0; j < cols; j++)
        {
            int latestPaintIndex = INT_MIN;         // // Last matrix cell of j'th column to get painted
            for(int i = 0; i < rows; i++)
            {
                latestPaintIndex = max(latestPaintIndex, elementToIndex[mat[i][j]]);
            }

            earliestColCompletion = min(latestPaintIndex, earliestColCompletion);
        }

        return min(earliestColCompletion, earliestRowCompletion);
    }
};
