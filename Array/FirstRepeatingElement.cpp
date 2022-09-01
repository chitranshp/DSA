
//{ Driver Code Starts
// https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) 
    {
        unordered_map<int, int> mymap;
        int i;
        for(i = 0; i < n; i++)
            mymap[arr[i]]++;
        for(i = 0; i < n; i++)
            if(mymap[arr[i]] > 1)
                return ++i;
        return -1;
        
    }
};

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}
