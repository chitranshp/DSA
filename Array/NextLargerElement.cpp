//https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> res;
        stack<long long> st;
        long long nge;
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && arr[i] >= st.top())
                st.pop();
                 
            if(!st.empty())
            {
                nge = st.top();
                st.push(arr[i]);
                res.push_back(nge);
            }
            else
            {
                nge = -1;
                st.push(arr[i]);
                res.push_back(nge);
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};