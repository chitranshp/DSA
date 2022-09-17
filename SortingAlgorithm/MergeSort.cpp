#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1; //Size of Left SubArray
    int n2 = r -m;  //Size of Right SubArray

    int a[n1];  //Left SubArray
    int b[n2];  //Right SubArray
    int i, j, k;    //Index for iterating over a,b and arr respectively.

    //Populating Left SubArray
    for(i = 0; i < n1; i++)
        a[i] = arr[l + i];
    
    //Populating Right SubArray
    for(j = 0; j < n2; j++)
        b[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    //Merge in a sorted order
    while(i < n1 && j < n2)
    {
        if(a[i] <= b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }

    while(i < n1)
        arr[k++] = a[i++];

    while(j < n2)
        arr[k++] = b[j++];

}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }
}

int main()
{
    int a[] = {2,6, 1, 9,8,5,13,11,10,45,9};
    mergeSort(a, 0, 10);
    for(int i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}