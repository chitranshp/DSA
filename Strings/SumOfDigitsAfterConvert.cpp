// https://leetcode.com/problems/sum-of-digits-of-string-after-convert

/*
TC - O(n) as 0 < k <= 10 which makes it almost constant or n becomes the asymptotically bigger term. If not, then O(n + k * log(n))
SC - O(1)
*/

class Solution {
public:
    int sumDigits(int num) 
    {
        int res = 0;
        while(num != 0)
        {
            res += num % 10;
            num /= 10;
        }

        return res;
    }

    int getLucky(string s, int k) {
        int res = 0;

        for(char &ch: s)
        {
            int num = ch - 'a' + 1;
            if(num >= 10)                   // Here 1 <= ch <= 26. So, max 2 digits only. We need sum of individual digits
                num = (num % 10) + (num / 10);

            res += num;
        }

        // 1 transformation is already done before this
        for(int i = 1; i < k; i++)
        {
            res = sumDigits(res);
        }

       return res;
    }
};
