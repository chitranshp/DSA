/* https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?page=1&sortBy=submissions */

#include <bits/stdc++.h>

using namespace std;

int majorityelement(int a[], int size)
{
    unordered_map<int, int> um;
        pair<int, int> res;
        res.first = 0;
        res.second = 0;
        for(int i = 0; i < size; i++)
        {
            um[a[i]]++;
            if(res.second < um[a[i]])
            {
                res.second = um[a[i]];
                res.first = a[i];
            }
        }
        if(res.second > size/2)
            return res.first;
        else
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