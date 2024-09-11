// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
// TC - O(1) as number of bits in xorVal will be constant either 32 bits or 64 bits
// SC - O(1)

class Solution {
public:
    int minBitFlips(int start, int goal) {
        unsigned int xorVal = start ^ goal;
        int ans = 0;

        while(xorVal != 0)
        {
            ans += (xorVal & 1);
            xorVal = xorVal >> 1;
        }

        return ans;
    }
};
