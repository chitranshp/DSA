//https://leetcode.com/problems/two-sum/
/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order. */

#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int, int> m;
    vector<int> res;
    int temp = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        temp = target - nums[i];
        if(m.find(temp) != m.end())
        {
            res.push_back(i);
            res.push_back(m[temp]);
            break;
        }
        m[nums[i]] = i;
    }
    return res;
}

int main()
{
    vector<int> vec = {2,7,11,15};
    vector<int> result;
    int target = 9;
    result = twoSum(vec, target);
    for(auto it : result)
        cout<<it<<" ";
    return 0;
}