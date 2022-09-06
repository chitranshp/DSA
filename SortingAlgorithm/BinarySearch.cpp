//https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1?page=1&difficulty[]=-1&difficulty[]=0&sortBy=submissions
#include <bits/stdc++.h>

using namespace std;

int binarysearch(int arr[], int n, int k) 
{
        int high = n - 1, low = 0, mid;
        while(high >= low)
        {
            mid = low + (high - low)/2;
            
            if(arr[mid] == k)
                return mid;
            else if(arr[mid] > k)
                high = mid - 1;
            else if(arr[mid] < k)
                low = mid + 1;
        }
        return -1;  //If element is not present in the array
}

int main()
{   
    int n, k;
    cin>>n; //Size of array
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cin>>k; //Target element
    cout<<binarysearch(a, n, k);
    return 0;
}