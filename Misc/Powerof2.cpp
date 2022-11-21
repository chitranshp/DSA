// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        //If n is a power of two, it must have only 1 bit as 1 ex. 10, 100, 1000, 001000000
        //Let's say n is 1000 then n - 1 will be 0111. n & (n - 1) = 0000. 
        //If it's not 0, then n must not be a power of 2.
        //If n <= 0, then also it's not a power of 2.
        
        return(n > 0 && !(n & (n - 1)));
    }
};
