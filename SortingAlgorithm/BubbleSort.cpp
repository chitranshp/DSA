#include <bits/stdc++.h>
using namespace std;

vector<int> sortArray(vector<int>& nums) 
{
    int i,j, swapped;
    for(i = 0; i < nums.size(); i++)
    {
        swapped = 0;
        for(j = 0; j < nums.size() - i - 1; j++)
        {
            if(nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                swapped = 1;
            }   
            
            
        }
        if(swapped == 0)
            break;
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