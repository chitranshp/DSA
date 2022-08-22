#include <bits/stdc++.h>
using namespace std;

vector<int> nextpermutation(vector<int> arr)
{
    int n = arr.size();
    int i, j;
    for(i = n - 2; i >= 0; i--)
        if(arr[i] < arr[i + 1])
            break;
    
    if(i < 0)
        reverse(arr.begin(), arr.end());
    else
    {
        for(j = n - 1; j >= 0; j--)
            if(arr[j] > arr[i])
                break;
        
        swap(arr[j], arr[i]);
        reverse(arr.begin() + i + 1, arr.end());
    }
    return arr;
}

int main()
{
    vector<int> arr = {2, 5, 4, 8, 7, 5};
    arr = nextpermutation(arr);
    for(auto it : arr)
        cout<<it<<" ";
    
    return 0;
}