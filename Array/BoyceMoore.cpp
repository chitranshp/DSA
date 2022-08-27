/* https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?page=1&sortBy=submissions */

#include <bits/stdc++.h>

using namespace std;

int majorityelement(int a[], int size)
{
    int candidate, count = 0;
    for(int i = 0; i < size; i++)
    {
        if(count == 0)
            candidate = a[i];
        
        if(candidate == a[i])
            count++;
        else
            count--;
    }
    return candidate;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<"\nMajority Element is:"<<majorityelement(arr, n);
    return 0;
}