//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
#include<bits/stdc++.h>
using namespace std;

//Naive Approach - O(n^2) and SC - O(1)
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
        {
               
            maxlen = max(maxlen, i - m[curr_sum]);
                
        }
        else
            m[curr_sum] = i;
            
    }
    return maxlen;
}

//Using HashMap - O(n) and SC - O(n)
int maxLen(vector<int>&A, int n)
{   
    int curr_sum = 0, maxlen = 0;
    int i, j;
    unordered_map<int, int> prefix_sum;
        
    for(i = 0; i < n; i++)
    {
        curr_sum += A[i];
            
        if(curr_sum == 0)
            maxlen = i + 1;
                
        if(prefix_sum.find(curr_sum) != prefix_sum.end())
            maxlen = max(maxlen, i - prefix_sum[curr_sum]);
        else
            prefix_sum[curr_sum] = i;
            
    }
    return maxlen;
}

int main()
{
    vector<int> v = {15, -2, 2, -8, 1, 7, 10, 23};
    cout<<"Length of largest subarray with Zero sum: "<<maxLen(v, 8);
    return 0;
}