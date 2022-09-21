/* Program to convert integer to equivalent binary number */
/* This can also be done through array and using bitwise operations */

#include <iostream>
#include <math.h>
using namespace std;
void DectoBin(int n)
{
    int cnt = 0, rem;
    long long int num = 0, temp;
    while(n > 0)
    {
        rem = n % 2;
        n = n / 2;
        temp = pow(10, cnt);
        num += rem * temp;
        cnt++;
    }
    cout<<"\n Equivalent binary number:"<<num;
}
int main()
{
    int num;
    cout<<"\n Enter a number:";
    cin>>num;
    DectoBin(num);
    return 0;
}