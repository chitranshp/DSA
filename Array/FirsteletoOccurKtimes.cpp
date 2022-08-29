//https://practice.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1?page=1&curated[]=1&sortBy=submissions
#include <bits/stdc++.h>
using namespace std;



class Solution{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            m[a[i]] = m[a[i]] + 1;
 
            if(m[a[i]] == k)
                return a[i];
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends