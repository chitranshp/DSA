/*https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1 */

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int max_sum = INT_MIN, max_till_here = 0;
        for(int i = 0; i < n; i++)
        {
            max_till_here += arr[i];
            if(max_sum < max_till_here)
                max_sum = max_till_here;
            
            if(max_till_here < 0)
                max_till_here = 0;
        }
        return max_sum;
        
    }
};

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}