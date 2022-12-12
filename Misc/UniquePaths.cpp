// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        // For m = 3 and n = 7, we have to take 2 and 6 steps as we are already standing in first cell.
        m = m - 1;
        n = n - 1;
        
        if(m < n)
            swap(m, n);

        //Simplify the formula, to avoid memory overflow. (m + n)!/m! * n!
        int j = 1;
        long res = 1;
        for(int i = m + 1; i <= (m + n); i++, j++)
        {
            res *= i;
            res /= j;
        }

        return (int) res;
    }
};
