#include<bits/stdc++.h>

using namespace std;

void reverseString(string &s,int p, int q)
{
    if(p >= q)
        return;
    
    swap(s[p++], s[q--]);
    reverseString(s, p, q);

    /*
    string dummy = ""; 
    if(index >= s.length())
        return;
    reverseString(s,index + 1, dummy);

    dummy.push_back(s[index]);

    */
}

int main()
{
    string s = "Hello";
    reverseString(s, 0, s.length() - 1);
    cout<<s;
    return 0;
}
