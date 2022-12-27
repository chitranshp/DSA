// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/submissions/866167824/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        long long int empty = 0;
        int i = 0;

        for(i = 0; i < capacity.size(); i++)
        {
            capacity[i] = capacity[i] - rocks[i];
            empty += capacity[i];
        }

        if(empty <= additionalRocks)
            return capacity.size();

        sort(capacity.begin(), capacity.end());
        int firstnonemptyIndex = lower_bound(capacity.begin(), capacity.end(), 1) - capacity.begin();
        for(i = firstnonemptyIndex; i < capacity.size() && capacity[i] <= additionalRocks; i++)
        {
            additionalRocks -= capacity[i];
            capacity[i] = 0;
        }

        return i;
    }
};
