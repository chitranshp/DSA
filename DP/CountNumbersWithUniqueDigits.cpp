// https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if(n == 0)
            return 1;

        int availabledigits = 9;
        long product = 9, totalcount = 10;

        /*
        T(2) = 9 * 9
        T(3) = T(2) * 8
        T(4) = T(3) * 7
        .....
        .....
        */
        //TC will be O(1) as it will iterate for maximum of 9 times(available digits > 0)
        for(int i = 2; i <= n && availabledigits > 0; i++, availabledigits--)
        {
            product = product * availabledigits;
            totalcount += product;
        }

        return totalcount;
        
    }
};
