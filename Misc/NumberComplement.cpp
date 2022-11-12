https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) 
    {
        unsigned mask = ~0;     //11111111
        while(num & mask)       //11111111 & 00000101
            mask = mask << 1;   //11111110  11111100   11111000

        return mask ^ (~num);   //1111110 ^ (111111010)
    }
};
