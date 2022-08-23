#include <bits/stdc++.h>
using namespace std;

void sortfun012(int a[], int n)
    {
        // code here 
        int low = 0, mid = 0, high = n-1;
        
        while(mid <= high)
        {
            if(a[mid] == 0)
            {
                swap(a[low], a[mid]);
                low++;
                mid++;
            }
            else if(a[mid] == 1)
            {
                mid++;
            }
            else if(a[mid] == 2)
            {
                swap(a[mid], a[high]);
                high--;
            }
        }
    }   

int main()
{
    int arr[] = {0, 2, 1 , 1 , 0, 2, 2, 2, 2,1, 1, 1, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortfun012(arr, n);
    for(auto it: arr)
        cout<<it<<" ";
    
    return 0;
}