//https://leetcode.com/problems/sum-of-two-integers/

class Solution {
public:
    int getSum(int a, int b) 
    {
        int c;
        while(b != 0)
        {
            c = a & b;      //Carry is only generatd when both of digits are 1.
            a = a ^ b;
             /*Handles the case, when one of them is negative. Left shifting negative int is not well defined in cpp standard. So, we convert into unsigned int and then store it into signed int which handles it */
            b = (unsigned int)c << 1;            //Left shifting one because, carry is added to the digit left of where it is generated.
        }
        return a;
    }
};