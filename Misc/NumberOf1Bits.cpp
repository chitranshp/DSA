// https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int total = 0;

        while(n)
        {
            if(n & 1 == 1)
                total++;

            n >>= 1;
        }    

        return total;
    }
};
