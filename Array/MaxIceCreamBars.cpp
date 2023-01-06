// https://leetcode.com/problems/maximum-ice-cream-bars/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        sort(costs.begin(), costs.end());
        int ans = 0;

        for(int i = 0; i < costs.size() && costs[i] <= coins; i++)
        {
            coins -= costs[i];
            ans++;
        }

        return ans;
    }
};
