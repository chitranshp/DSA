// https://practice.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/0


/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        int count = 0;
        
        while(N > 0)
        {
            //This operation reduces length of each subgroup of consecutive ones's by 1.
            // Ex. 11011101 & 10111010 = 10011000
            // TC = O(logN) as each loop will have log2(N) iterations.
            N = N & (N << 1);
            count++;
        }
        
        return count;
    }
};