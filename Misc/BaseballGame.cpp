// https://leetcode.com/problems/baseball-game/solutions/

/*
TC - O(n) + O(n)
SC - O(n)
*/

class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        stack<int> st;
        int sum = 0;

        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i] == "D")
            {
                st.push(2 * st.top());
            }    
            else if(operations[i] == "C")
            {                
                st.pop();
            }    
            else if(operations[i] == "+")
            {
                int val = st.top();
                st.pop();

                val += st.top();
                st.push(val - st.top());

                st.push(val); 
            }
            else
            {
                st.push(stoi(operations[i]));
            }
        }

        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};