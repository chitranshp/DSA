/* https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?page=1&sortBy=submissions */

/* 
    Approach 1: Using Hashing
    TC - O(n)
    SC - O(n)
*/

#include <bits/stdc++.h>

using namespace std;

int majorityelement(int a[], int size)
{
    unordered_map<int, int> um;
        int threshold = size / 2;
        
        for(int i = 0; i < size; i++)
        {
            if(++um[a[i]] > threshold)
                return a[i];
        }
        
        return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<majorityelement(arr, n);
    return 0;
}
