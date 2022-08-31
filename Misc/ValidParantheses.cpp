//https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) 
{
    stack<char> verify;
    unordered_map<char, char> charpairs = {{'(',')'}, {'[',']'}, {'{','}'}};
    char c;
    for(int i = 0; i < s.length(); i++)
    {
            
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
            verify.push(s[i]);
        else
        {
            if(verify.empty())
                return false;
            c = verify.top();
                
            if(charpairs[c] != s[i])
                return false; 
            else if(!s.empty())
                verify.pop();       
        }
    }
    return (verify.empty()? true:false);
}

int main()
{
    string word;
    cin>>word;
    cout<<isValid(word);
    return 0;
}