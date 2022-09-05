// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
        
    }
    void convertToWave(vector<int>& arr, int n)
    {
        int i=0;
        for(i = 0; i<n-1; i=i+2)
        {
            if(i>0 && arr[i-1]> arr[i])
                swap(&arr[i],&arr[i-1]);
            if(i<n-1 && arr[i]<arr[i+1])
                swap(&arr[i+1], &arr[i]);
        }
    }
};

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) 
    {
        cin>>n; //input size of array
        vector<int> a(n); //declare vector of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        Solution ob;
        ob.convertToWave(a, n);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}