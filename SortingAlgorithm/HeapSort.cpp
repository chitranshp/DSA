//https://practice.geeksforgeeks.org/problems/heap-sort/1

#include <bits/stdc++.h>
using namespace std;

//MaxHeap
void heapify(int arr[], int n, int i)  
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest;
      
    if(arr[l] > arr[i] && l < n)
        largest = l;
    else 
        largest = i;
      
    if(arr[r] > arr[largest] && r < n)
        largest = r;
      
    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }   
}

//Function to build a Heap from array.
void buildHeap(int arr[], int n)  
{ 
    for(int i = n/2; i >= 0; i--)
        heapify(arr, n, i);
}


//Function to sort an array using Heap Sort.
void heapSort(int arr[], int n)
{
    int heapsize = n;
    buildHeap(arr, n);
    for(int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        heapsize = heapsize - 1;            //Instead, we can use 'i' also.
        heapify(arr, heapsize, 0);
    }
}

int main()
{
    int n,ele;
    cin>>n;     //Size
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        arr[i] = ele;
    }
    
    heapSort(arr, n);
    for(auto it: arr)
        cout<<it<<" ";
    return 0;
}