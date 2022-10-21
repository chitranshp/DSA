//leetcode.com/problems/reverse-integer/



int reverse(int x)
{
    long long int rev = 0, rem = 0;
    int signflag = x >= 0? 1: -1;
    
    while(x)
    {
        rem = x % 10;
        rev = rev * 10 + rem;
        x = x / 10;
        
        if(rev * signflag > INT_MAX || rev * signflag < INT_MIN)
            return 0;
    }
    
    return rev;
}
