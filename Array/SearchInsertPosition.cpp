#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) 
    {
        int index;
        auto it = find(nums.begin(), nums.end(), target);
        if(it == nums.end())
            index = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        else
            index = it - nums.begin();
        return index
        
        /* Using Lower bound */
        //return (lower_bound(nums.begin(), nums.end(), target) - nums.begin());
    }

int main()
{
    vector<int> vec = {3, 5, 8, 9, 13};
    int t = 12;
    cout<<searchInsert(vec, t);
    return 0;
}