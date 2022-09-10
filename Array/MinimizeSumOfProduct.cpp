//https://practice.geeksforgeeks.org/problems/minimize-the-sum-of-product1525/1
#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        long long int ans = 0;
        sort(a, a + n);       //ascending order
        sort(b, b + n, greater<int>());         //Descending order
        
        for(int i = 0; i < n; i++)
            ans += a[i]*b[i];
            
        return ans;
    }
};

int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}
