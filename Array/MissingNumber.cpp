//https://leetcode.com/problems/missing-number/

#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) 
{
    int runningsum = 0, n = nums.size();
    int expectedsum = (n + 1)*n / 2;
        
    for(int i = 0; i < n; i++)
        runningsum += nums[i];
        
    return expectedsum - runningsum;
}

int main()
{
    vector<int> vec = {2, 4, 1, 0, 5};
    int ans = missingNumber(vec);
    cout<<ans;

    return 0;
}