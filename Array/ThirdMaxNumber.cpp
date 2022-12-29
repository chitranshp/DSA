// https://leetcode.com/problems/third-maximum-number/description/

class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        int i = 0, max = 0, temp;
        priority_queue<int> pq(nums.begin(), nums.end());   //O(n)

        max = pq.top();
        while(i < 2 && pq.size())
        {
            temp = pq.top();
            while(pq.size() && temp == pq.top())
                pq.pop();

            ++i;
        }

        return (!pq.size()) ? max : pq.top();
    }
};
