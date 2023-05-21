// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?leftPanelTab=1

#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> nse(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) 
    {
      while (!st.empty() && st.top() >= arr[i])
        st.pop();

      nse[i] = (st.empty() == true) ? -1 : st.top();
      st.push(arr[i]);
    }
        
    return nse;
}



// if(st.empty() == true)
        // {
        //     st.push(arr[i]);
        //     nse[i] = -1;
        // } 
        // else if(st.top() >= arr[i])
        // {
        //     while(st.empty() != true && st.top() >= arr[i])
        //     {
        //         st.pop();
        //     }

        //     if(st.empty() != true)
        //         nse[i] = st.top();

        //     st.push(arr[i]);
        // }
        // else
        // {
        //     nse[i] = st.top();
        //     st.push(arr[i]);
        // }
