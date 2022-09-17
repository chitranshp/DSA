#include<bits/stdc++.h>
using namespace std;
int maxLen(vector<int>&A, int n)
{   
    int curr_sum = 0, maxlen = 0;
    int i, j;
    unordered_map<int, int> m;
        
    for(i = 0; i < n; i++)
    {
        curr_sum += A[i];
            
        if(curr_sum == 0)
            maxlen = i + 1;
                
        if(m.find(curr_sum) != m.end())
            maxlen = max(maxlen, i - m[curr_sum]);
        else
            m[curr_sum] = i;
            
    }
    return maxlen;
}

int main()
{
    vector<int> v = {15, -2, 2, -8, 1, 7, 10, 23};
    cout<<"Length of largest subarray with Zero sum: "<<maxLen(v, 8);
    return 0;
}