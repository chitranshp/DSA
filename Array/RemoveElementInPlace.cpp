#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) 
{
    int count = 0, flag = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == val)
        {
            count++;
            flag = 1;
        }    
        else
            nums[i - count] = nums[i];
    }
    return nums.size() - count;
}

int main()
{
    vector<int> a = {4, 2, 2, 5, 7, 9, 12, 34, 45,2 ,7, 2, 9};
    int target = 2; //for removal
    int index;
    index = removeElement(a, target);

    for(int i = 0; i < index; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}