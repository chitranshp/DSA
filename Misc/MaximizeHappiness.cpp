// https://leetcode.com/problems/maximize-happiness-of-selected-children/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq(happiness.begin(), happiness.end());
        long long res = 0;

        int cntr = 0;
        while(cntr < k) {
            int ele = pq.top();
            pq.pop();

            ele = max(0, ele - cntr);

            res += ele;
            cntr++;
        }

        return res;
    }
};
