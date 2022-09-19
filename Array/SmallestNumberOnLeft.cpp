#include <bits/stdc++.h>
using namespace std;

vector<int> leftSmaller(int n, int arr[])
{
    stack<int> st;
    vector<int> lse;
        
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && st.top() >= arr[i])
            st.pop();
                
        if(!st.empty())
        {
            lse.push_back(st.top());
            st.push(arr[i]);
        }
        else
        {
            lse.push_back(-1);
            st.push(arr[i]);
        }
    }
    return lse;
}

int main()
{
    int nums1[] = {1, 5, 0, 3, 4, 5};
    vector<int> ans = leftSmaller(6, nums1);

    for(auto it: ans)
        cout<<it<<" ";

    return 0;
}