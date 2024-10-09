// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

/*
We are only concerned with closing brackets (']') that don't have matching opening brackets ('[') before them. These are the 
"unbalanced" brackets.
Each swap can balance two unbalanced CLOSING brackets(not talking about a pair of opening and closing brackets)

For ex. ))(( -> Swapping 0 with 3
        ()() -> One unbalanced pair swap fixed two unbalanced CLOSING brackets which are 0th and 1st. i.e. One swap fixes two unbalanced clsoing brackets

Therefore, for n unmatched closing brackets n / 2 swaps will be required to fix it. 
But for cases where n is odd ex. 3 unbalanced closing brackets ]]][[[ -> []][][ -> [[][]] 2 swaps are required
3 / 2 = 1. So, for odd cases we can use (n + 1) / 2. 
For even 2 unbalanced brackets = 3 / 2 = 1. Still holds

So minimum swaps = (number of unbalanced closing/opening brackets + 1) / 2
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    int minSwaps(string s) {
        int unbalanced = 0;
        stack<char> st;

        for(int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if(s[i] == ']')
            {
                if(st.empty())
                    unbalanced++;
                else
                    st.pop();
            }
            else 
            {
                st.push(ch);
            }
        }

        return (unbalanced + 1) / 2;
    }
};

/*
Space optimized version: We only need the number of unbalanced closing brackets and nothing else. So, we will count only those
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    int minSwaps(string s) {
        int unbalanced = 0, opening = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ']')
            {
                if(opening > 0)
                    opening--;
                else
                    unbalanced++;        
            }
            else 
            {
                opening++;
            }
        }

        return (unbalanced + 1) / 2;
    }
};
