/* https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1 */

#include <bits/stdc++.h>

using namespace std;


class Solution{
public:

	void rearrange(int arr[], int N) {
	    // code here
	    vector<int> pos, neg;
	    int p = 0, n = 0;
	    int i = 0;
	    bool flag = true;
	    for(int i = 0; i < N; i++)
	    {
	        if(arr[i] >= 0)
	            pos.push_back(arr[i]);
	        else
	            neg.push_back(arr[i]);
	    }
	    
	    i = 0;
	    while(i < N)
	    {
	        if(p < pos.size())
	            arr[i++] = pos[p++];
	        if(n < neg.size())
	            arr[i++] = neg[n++];
	    }
	    
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}