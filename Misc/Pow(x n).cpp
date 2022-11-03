// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) 
    {
        double temp;
        if(n == 0)
            return 1;
        
        if(n < 0)
            x = 1/x;
        
        temp = pow(x, abs(n/2));
        
        return (n & 1)? x * temp * temp: temp* temp;
    }
};
