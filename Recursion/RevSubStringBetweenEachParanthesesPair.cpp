// Each level of nesting adds another layer of reversing. The innermost character gets reversed at each level of nesting.
// Therefore Total TC = O(n ^ 2) & SC = O(n)

class Solution {
public:
    string helper(int &i, const string &s) {
        string rev = "";
        i++;    // To skip opening paranthesis

        while(i < s.size() && s[i] != ')') {
            if(s[i] != '(') {
                rev += s[i];
            }
            else if(s[i] == '(') {       //If we encounter nested opening parantheses
                rev += helper(i, s);
            }

            i++;    // Will skip to next alphabet or skip the closing nested parantheses
        }

        reverse(rev.begin(), rev.end());  
        return rev;
    }
    string reverseParentheses(string s) {
        string rev = "";

        for(int i = 0; i < s.size(); i++) { // O(n)
            if(s[i] == '(') {
                rev += helper(i, s);
            }
            else {
                rev += s[i];
            }
        }

        return rev;
    }
};

// Without Recursion

class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<int> openedPosition;

        for(int i = 0; i < s.size(); i++) { 
            if(s[i] == '(') {
                openedPosition.push(res.length());    // This will actually point to the next char in res
            }
            else if(s[i] == ')') {
                int j = openedPosition.top();
                openedPosition.pop();
                reverse(res.begin() + j, res.end());
            }
            else {
                res += s[i];
            }
        }

        return res;
    }
};
