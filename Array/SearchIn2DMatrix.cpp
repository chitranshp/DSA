// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //int low = 0, high = m * n - 1, mid, num;
        /*
        We start from last element in first row.
        int i = 0, j = matrix[0].size() - 1;

        while(i < matrix.size() && j >= 0)
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else
                i++;
        }
        */

        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1, mid, num;
        
        while(low <= high)
        {
            mid = low + (high - low)/2;
            num = matrix[mid / n][mid % n];
            if(num == target)
                return true;
            else if(num < target)
                low = mid + 1;
            else    
                high = mid - 1;
        }
         return false;
    }
};







