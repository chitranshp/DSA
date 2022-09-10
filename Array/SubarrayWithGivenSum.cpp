//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int current_sum = arr[0], beg = 0, end, i;
        for(i = 1; i < n; i++)
        {
            while(current_sum > s && beg < i - 1)
            {
                current_sum -= arr[beg];
                beg++;
            }
            
            if(current_sum == s)
                return {beg +  1, i};
            
            current_sum += arr[i];
        }
        return {-1};
    }
};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
