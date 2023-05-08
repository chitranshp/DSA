// https://leetcode.com/problems/matrix-diagonal-sum/description/

/*
TC - O(n * n)
SC - O(1)
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    sum += mat[i][j];
                else if(i + j == n - 1)
                    sum += mat[i][j];
            }
        }

        return sum;
    }
};

/*

For diagonal 1 - i will always be equal to j
For diagonal 2 - 
        i + j = n - 1
        j = n - 1 - i

We don't need to iterate for j separately, We can just iterate over i and use i's value to get corresponding j for diagonal

Only issue will be when both diagonals have one common element i.e. middle element for ex. when n = 3, i = 1 and j = 1 will be part of both diagonals
In that case, we will have to subtract one mat[n/2][n/2] from total sum.

This will only happen when n is odd.

TC - O(n)
SC - O(1)
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++)
        {
            sum = sum + mat[i][i] + mat[i][n - 1 - i];
            /*
            sum += mat[i][i];
            if(i != n - 1 - i)      //if(i != j)
                sum += mat[i][n - 1 - i];
            */
        }

        if(n % 2 == 1)
            sum -= mat[n / 2][n / 2];

        return sum;
    }
};