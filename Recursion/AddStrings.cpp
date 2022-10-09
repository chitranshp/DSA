//https://leetcode.com/problems/add-strings/submissions/

class Solution {
public:
    void addHelper(string &num1, string &num2, int p, int q, int carry, string &ans)
    {
        if(p < 0 && q < 0 && carry == 0)
        {
            return;
        }
        
        int first = 0;
        int second = 0;
        int csum = 0;
        
        if(p >= 0)
            first = num1[p] - '0';
        if(q >= 0)
            second = num2[q] - '0';
        
        csum = first + second + carry;
        carry = csum/10;
        csum = csum % 10;
        ans.push_back(csum + '0');
        
        addHelper(num1, num2, p - 1, q - 1, carry, ans);
        
    }
    string addStrings(string num1, string num2) 
    {
        string res;
        addHelper(num1, num2, num1.length() - 1, num2.length() - 1, 0, res);

        //Handles leading zeroes. (00000 and 00)
        while(res.back() == 0 && res.size() > 1)
            res.pop_back();

        reverse(res.begin(), res.end());
        return res;
    }
};