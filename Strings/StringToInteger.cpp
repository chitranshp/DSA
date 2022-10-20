//leetcode.com/problems/string-to-integer-atoi

class Solution
{
public:
    int myAtmyAtoioi(string s) 
    {   
        long long int res = 0, signflag = 1;
        bool flag = 0;
        int i = s.find_first_not_of(' ');

        /*Check for i's position, for the case when string is empty or only consists of spaces. Then, it won't increment i*/
        if(i < s.length() && (s[i] == '+' || s[i] == '-'))      
            signflag = (s[i++] == '-')?-1:1;
        
        while(i < s.length() && isdigit(s[i]))
        {
            flag = 1;                                   //Signals atleast 1 int were read;
            res = res*10 + (s[i++] - '0');              //Increment i for next iteration
            if(res * signflag > INT_MAX)
                return INT_MAX;
            else if(res * signflag < INT_MIN)
                return INT_MIN;
        }
        
        if(!flag)                               //If no int were read, return 0
            return 0;
          
        res *= signflag;
        return res;
        
    }
};
