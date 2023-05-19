// https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650
// https://leetcode.com/problems/evaluate-boolean-expression/

/*
        Only operators as per question are OR(+), AND(&) and XOR(^). All of which are binary operators.
        Given expr:
                    operand operator operand operator operand operator operand
        We can see that expression will always start with an operand and end with an operand.
        All operators will be present between 2 operands.
        If we start from ith char(operand), we will find next consecutive operators after 2 steps, i.e. i + 2

        At every operator we have a choice to paranthesise(divide) the problem into two parts
        Let's say operator is at index 'ind'
            We can divide it into two subproblems f(i, ind - 1) & f(ind + 1, j)

    Now second part of the problem is to figure out the number of ways in which these subproblems evaluate to true.
    In case of & operator
        Number of ways left subproblem evaluate to true * Number of ways right subproblem evaluates to true.

    For | operator
        lT * rT + lF * rT * lT * rF

    For ^ 
        lT * rF + lF * rT

    Now for evaluating these subproblems, we can keep on dividing these subproblems till only single element is left
    And the value of that element will be the result of that smallest sub expression.
    By using that in parent recursive calls, we can calculate the number of ways our expression evaluates to true.

    Since, we also have to find the number of ways a problem evaluates to false, for our formulae's 
    we will use another boolean variable to indicate whether we are trying to find number of ways that problem evaluates to true or false/

    TC - Exponential.
    SC - O(n) for stack space
*/
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

    // Since, we are trying to calculate all possible ways our boolean expression to true, we will add current ways to the new total.
    //          ways = ways + f();
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

/*
TC - O(n * n * 2 * n) approx O(n ^ 3). Here O(n * n * 2) is for states and another O(n) is due to for loop.
SC - O(n * n * 2) + O(n)
*/

#include <bits/stdc++.h> 
long long int mod = 1000000007;
int expr(string& exp, int i, int j, int isTrue, vector<vector<vector<int>>> &dp)
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

    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    long long int ways = 0;
    // j = n - 1, which will always be an operand. And index is being used to iterate over operators.
    for(int index = i + 1; index < j; index+= 2)
    {
        long long int lT = expr(exp, i, index - 1, 1, dp) % mod;
        long long int lF = expr(exp, i, index - 1, 0, dp) % mod;
        long long int rT = expr(exp, index + 1, j, 1, dp) % mod;
        long long int rF = expr(exp, index + 1, j, 0, dp) % mod;

        if(exp[index] == '&')
        {
            if(isTrue == 1)
                ways = ways + (lT * rT) % mod;
            else
                ways = ways + (lT * rF + lF * rT + lF * rF) % mod;
        }
        else if(exp[index] == '|')
        {
            if(isTrue == 1)
                ways = ways + (lT * rF + lF * rT + lT * rT) % mod;
            else
                ways = ways + (lF * rF) % mod;
        }
        else if(exp[index] == '^')
        {
            if(isTrue == 1)
                ways = ways + (lT * rF + lF * rT) % mod;
            else
                ways = ways + (lT * rT + lF * rF) % mod;
        }
    }

    return dp[i][j][isTrue] = ways % mod;
}

int evaluateExp(string & exp) 
{
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));
    return expr(exp, 0, exp.size() - 1, 1, dp);

}

/*
Here instead of using another for loop to iterate over isTrue, we have calculated both isTrue and isFalse separately for each index
TC - O(n * n * 2 * n)
SC - O(n * n * 2)
*/

int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, 0)));

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = i; j <= n - 1; j++) //Instead of j = 0, we can start from j = i, as the case where i > j is handled as part of vector initialization
        {
            long long int waysT = 0, waysF = 0;

            if(i == j) 
            {
                dp[i][j][1] = exp[i] == 'T';
                dp[i][j][0] = exp[i] == 'F';
                continue;
            }
            // j = n - 1, which will always be an operand. And index is being used to iterate over operators.
            for(int index = i + 1; index < j; index+= 2)
            {
                long long int lT = dp[i][index - 1][1] % mod;
                long long int lF = dp[i][index - 1][0] % mod;
                long long int rT = dp[index + 1][j][1] % mod;
                long long int rF = dp[index + 1][j][0] % mod;

                if(exp[index] == '&')
                {
                    
                        waysT = waysT + (lT * rT) % mod;
                    
                        waysF = waysF + (lT * rF + lF * rT + lF * rF) % mod;
                }
                else if(exp[index] == '|')
                {
                    
                        waysT = waysT + (lT * rF + lF * rT + lT * rT) % mod;
                        waysF = waysF + (lF * rF) % mod;
                }
                else if(exp[index] == '^')
                {
                        waysT = waysT + (lT * rF + lF * rT) % mod;
                        waysF = waysF + (lT * rT + lF * rF) % mod;
                }
            }

            dp[i][j][1] = waysT % mod;
            dp[i][j][0] = waysF % mod;
        }
    }
    
    return dp[0][n -1][1];

}