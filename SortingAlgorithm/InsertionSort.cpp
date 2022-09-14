#include <bits/stdc++.h>
using namespace std;

vector<int> sortArray(vector<int>& nums) 
{
    int i,j, key;
    for(i = 1; i < nums.size(); i++)
    {
        key = nums[i];
        j = i - 1;
        while(j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
    return nums;
}

int main()
{
    vector<int> vec;
    int n,ele;
    cin>>n;     //Size
    cin>>ele;
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        vec.push_back(ele);
    }
    sortArray(vec);
    for(auto it: vec)
        cout<<it<<" ";
    return 0;
}