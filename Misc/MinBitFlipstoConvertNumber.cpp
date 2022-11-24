// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        // TC O(logn)
        /*
        int cnt = 0;
        int xorval = start ^ goal;

        while(xorval)
        {
            if(xorval & 1)
                cnt++;
            
            xorval = xorval >> 1;
        }

        return cnt;
        */
        
      
        //Kernighan's algorithm
        int cnt = 0;
        int xorval = start ^ goal;

        //Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit. 
        // ex. Decimal val of(1110110) - 1 = 1110101 
        //TC - O(logn)
        while(xorval)       //The number of times this loop runs will equal to number of set bits
        {                   //Max set bits in for a decimal no. 'n' will be logn. Hence Worst   case TC O(logn)
            xorval = xorval & (xorval - 1);
            cnt++;
        }

        return cnt;
    }
};
