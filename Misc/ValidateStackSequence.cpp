// //https://leetcode.com/problems/validate-stack-sequences/description/

/*
TC - O(N)
SC - O(N) for stack
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        bool res = true;
        stack<int> st;
        int i = 0, j = 0;
        int m = pushed.size();
        //Pushed.legnth == popped.length(as per constraint)

        while(i < m)
        {
            if(i < m)
                st.push(pushed[i++]);

            //j will always be less than or equal to i, as we cannot pop more elements than what are present in stack. So, if at a time t, i is less than m, j will also be < m.
            while(!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }    
        }

        /*
        if(j < n && i == m)
            return false;
        else if(j == n && i == m)
            return true;
        */

        return st.empty();  //true when j == n && i == m, false otherwise
    }
};

/*
Two pointer approach and simulating input vector as a stack.
TC - O(n) - At max there can be n push and n pops which is O(n) + O(n)
SC - O(1) - We are using the input vector only
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int j = 0, top = -1;
        int m = pushed.size();
        //Pushed.legnth == popped.length(as per constraint)

        for(int i = 0; i < m; i++)
        {
            top = i;

            while(top >= 0 && j < m && ( pushed[top] == popped[j] || pushed[top] == -1))
            {
                //This element is pushed and popped already
                if(pushed[top] == -1)
                {
                    top--;      
                    continue;
                }    

                pushed[top] = -1;   //To indicate this element has been pushed and popped already
                top = top - 1;
                j++;
            }    
        }

        return j == m;  //true when j == n && i == m, false otherwise
    }
};