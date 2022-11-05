// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i = a.length() - 1, j = b.length() - 1, sum = 0, carry = 0;
        string res = "";
        int first = 0, second = 0;

        while( i >= 0 || j >= 0 || carry != 0)
        {
            first = 0;
            second = 0;

            if(i >= 0)
                first = a[i--] - '0';

            if(j >= 0)
                second = b[j--] - '0';

            sum = first ^ second ^ carry;
            carry = (first & second) || (first & carry) || (second & carry);    
            res += (sum + '0');

        }

        reverse(res.begin(), res.end());
        return res;
    }
};
