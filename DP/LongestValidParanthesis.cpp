// https://leetcode.com/problems/longest-valid-parentheses/

/*
DP - We will create a vector dp of size n, where each dp[i] will represent length of longest valid paranthesis at that index.

    If s[i] = '('
        set dp[i] = 0 as no valid paranthesis sequence will end in '('. They will always end in ')'.
    else
    {
        if(s[i - 1] == '(')
        Then we will update the dp[i] = dp[i - 2] + 2. Two is added for s[i - 1] and s[i] which are '(' and ')' respectively.
        We are just appending 2 to the longest paranthesis sequence ending at s[i - 2].
        ex. (((()))) ()
                   4  4 + 2 = 6

        else if(s[i - 1] == ')')
        This means, there is another paranthesis sequence ending at s[i - 1]. 
    We will include the length of that sequence in our dp[i], we IF AND ONLY IF WE can find a valid opening index for s[i] .
    That character will be at 1 PLACE BEFORE the corresponding starting paranthesis for s[i - 1]
                0123456i
        for ex. ()(()())
            do  02002048
                s[i - 1] is ')' and dp[i - 1] is 4.     
                We will try to find the starting index for sequence ending at dp[i - 1] which is actually 1 (s[1] = '(')
                i - dp[i - 1] - 1 = 7 - 4 - 1 = 2 WHICH IS 1 PLACE BEFORE STARTING INDEX OF s[i - 1]. This is the opeing index of s[i].     
                If that starting char is '(' which makes s[i] = ')' a valid pair of paranthesis, we will add 2 and include the length of sequence contained in dp[i - 1]
                dp[i] = dp[i - 1] + 2 = 4 + 2          //If s[i - dp[i - 1] - 1] == '('

                BUT in given example, we can see that s[2] = '(' and s[2] till s[7] is a valid sequence of length 6.
                BUT there is a another sequence ending at s[2 - 1] of length 2 which is not included yet.

                So we need to modify the dp[i] formula.
                If 1 place before the starting index(2) of corresponding VALID pair of s[i] is ')' the ending of a valid paranthesis sequence. We will include the length of that sequence also. This is only if s[i - dp[i - 1] - 2] is ')', else we will just add 0 or not add anything with the previous term.
                Therefore, dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 1] + dp[i - dp[i - 1] - 2]



    }       
TC - O(n)
SC - O(n)
*/
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n = s.size();
        int maxi = 0;
        vector<int> dp(n, 0);

        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == '(')
                dp[i] = 0;
            else if(s[i] == ')')
            {
                if(s[i - 1] == '(')
                    dp[i] = (i - 2) >= 0? dp[i - 2] + 2 : 2;          //2 for pair (). Also verify that i - 2 is a valid index
                //Verify that 'i - dp[i - 1] - 1' and 'i - dp[i - 1] - 2' are valid indexes before using them.
                //We can remove s[i - dp[i - 1] - 1] == '(' and s[i - dp[i - 1] - 2] == ')' as is that is not true dp[_] will be equal to 0.
                else if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2 >= 0)? dp[i - dp[i - 1] - 2] : 0);

            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};