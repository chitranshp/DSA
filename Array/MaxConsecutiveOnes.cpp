//https://leetcode.com/problems/max-consecutive-ones/

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int  candidate = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                ans = max(ans, ++candidate);
            else
                candidate = 0;
            
        }
        return ans;
    }

int main()
{
    vector<int> v = {1, 1, 2, 3, 1, 1, 1, 1,6, 1, 1, 1, 1, 1, 1, 1, 7 ,7 , 1, 1, 1,};
    cout<<findMaxConsecutiveOnes(v);
    return 0;
}