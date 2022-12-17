// https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/861105817/

class Solution {
public:
    int evalRPN(vector<string>& tokens)     //It is a vector of strings.
    {
        stack<long> operands;
        long rightoperand, leftoperand;
        for(int i = 0; i < tokens.size(); i++)
        {
            /*If it is a operator, it's size will be definately equal to 1. So, tokens[i].size() > 1 handles all negative numbers and operators. As negative numbers will have a size of atleast 2 ('-' and digit). 
            Remaining case that we still need to handle is of single digit positive numbers. For them we only check if first char of string is digit or not. If it is a digit, we push the whole string to stack.
            */
            if(tokens[i].size() > 1 || isdigit(tokens[i][0]))
                operands.push(stoi(tokens[i]));     //stoi for converting string to integer.
            else
            {
                rightoperand = operands.top();  operands.pop();
                leftoperand = operands.top();   operands.pop();

                if(tokens[i] == "+")
                    leftoperand += rightoperand;
                if(tokens[i] == "-")
                    leftoperand -= rightoperand;
                if(tokens[i] == "*")
                    leftoperand *= rightoperand;
                if(tokens[i] == "/")
                    leftoperand /= rightoperand;
                operands.push(leftoperand);
            }
        }

        return operands.top();
    }
};
