#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) 
{
        
        long rev = 0;
        int rem, n = x;
        while(n >= 1)
        {
            rem = n % 10;
            n = n / 10;
            rev = rev*10 + rem;
        }
        //cout<<rev;                
        if(rev == x)
            return true;
         else
             return false;
}

int main()
{
    int num;
    cin>>num;
    cout<<isPalindrome(num);
    return 0;
}