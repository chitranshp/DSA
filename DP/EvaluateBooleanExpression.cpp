// https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650
// https://leetcode.com/problems/evaluate-boolean-expression/

#include <bits/stdc++.h> 
long long int mod = 1000000007;
int expr(string& exp, int i, int j, int isTrue)
{
    if(i > j)
        return 0;

    if(i == j) 
    {
        if(isTrue == 1)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    long long int ways = 0;
    // j = n - 1, which will always be an operand. And index is being used to iterate over operators.
    for(int index = i + 1; index < j; index+= 2)
    {
        long long int lT = expr(exp, i, index - 1, 1) % mod;
        long long int lF = expr(exp, i, index - 1, 0) % mod;
        long long int rT = expr(exp, index + 1, j, 1) % mod;
        long long int rF = expr(exp, index + 1, j, 0) % mod;

        if(exp[index] == '&')
        {
            if(isTrue == 1)
                ways = ways + (lT * rT) % mod;
            else
                ways = ways + ((lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
        }
        else if(exp[index] == '|')
        {
            if(isTrue == 1)
                ways = ways + ((lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) % mod;
            else
                ways = ways + (lF * rF) % mod;
        }
        else if(exp[index] == '^')
        {
            if(isTrue == 1)
                ways = ways + ((lT * rF) % mod + (lF * rT) % mod) % mod;
            else
                ways = ways + ((lT * rT) % mod + (lF * rF) % mod) % mod;
        }
    }

    return ways % mod;
}

int evaluateExp(string & exp) 
{
    int n = exp.size();
    return expr(exp, 0, exp.size() - 1, 1);
}