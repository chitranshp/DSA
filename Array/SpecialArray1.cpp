// https://leetcode.com/problems/special-array-i

/*
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool isSpecial = true;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] % 2 == nums[i + 1] % 2)
                return false;
        }

        return isSpecial;
    }
};

// Using bitwise operators
/*
An odd number will always have it's LSB as 1. (2^0 + 2^1 + 2^2 + .... + 2^n for this to be odd 2^0 i.e. LSB bit must have to be 1 as sum of even numbers will always be even)
And similarly for even number MSB bit must be 0. So, if two numbers have different parity that means one of them has 0 as LSB and other has 1. 
1. If we perform an XOR, the result will always have 1 as LSB (0 ^ 1 = 1). 
    nums[i] ^ nums[i + 1]
2. Now to check the value of LSB in result, we can isolate it by performing an AND operation with 1. 
    (nums[i] ^ nums[i + 1]) & 1 
  If this is 0, that means both numbers are of same parity and result of their XOR had 0 in LSB.

Note: == has higher precedency then &
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool isSpecial = true;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(((nums[i] ^ nums[i + 1]) & 1) == 0)     // (!((nums[i] ^ nums[i + 1]) & 1))
                return false;
        }

        return isSpecial;
    }
};

*/
