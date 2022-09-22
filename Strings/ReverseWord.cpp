#include <bits/stdc++.h>
using namespace std;

string reverseWord(string str)
{
    int n = str.size();
    
    for(int i = 0; i < n/2; i++)
        swap(str[i], str[n - i - 1]);

    return str;
}

int main()
{
    string ip = "hello";
    string reversedip = reverseWord(ip);
    cout<<reversedip;
    return 0;
}