//https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) 
    {
        int res = 0;
        while(n >= 5)
        {
            n = n / 5;
            res += n;
        }
        return res;
    }
};