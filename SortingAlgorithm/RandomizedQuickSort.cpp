#include<bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedpartition (int arr[], int low, int high)
{
    srand(time(0));
    int n = rand();
    int pivot = low + (high - low) % n;
       
    swap(arr[high], arr[pivot]);
    return partition(arr, low, high);     
}

void quickSort(int arr[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = partition(arr, low, high);
        quickSort(arr, low, mid - 1);
        quickSort(arr, mid + 1, high);
    }
}

int main()
{
    int a[] = {2,6, 1, 9,8,5,13,11,10,45,9};
    quickSort(a, 0, 10);
    for(int i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}