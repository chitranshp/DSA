/*   C++ implementation of For each element in 1st array count elements less than or equal to it
in 2nd array*/

/* https://practice.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1 */

#include <bits/stdc++.h>
 
using namespace std;

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        vector<int> vec;
        int count = 0;
        sort(arr2, arr2 + n);
        for(int i = 0; i < m; i++)
        {
            count = upper_bound(arr2, arr2 + n, arr1[i]) - arr2;
            vec.push_back(count);
        }
        return vec;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}