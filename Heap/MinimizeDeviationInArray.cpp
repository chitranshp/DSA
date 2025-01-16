// https://leetcode.com/problems/minimize-deviation-in-array/

/*
Deviation = maxVal - minVal. Similaryly, min Deviation = min(maxVal - minVal);

Based, on problem constraint, odd numbers can only be increased whereas even numbers can only be increased
To simplify problem, we convert all odd numbers to even by * 2 and push all the numbers (odd & even) to a max queue to track max and track minimum using a varialbe


Now, we keep dividing the max element untill, it becomes odd.
Then no further divisions is allowed and any further operation on it will lead to max value to increase only(as odd can be * 2 only)
And in each of this step, we will track the difference between min & max value
And at the point when no subsequent operations can be allowed, we will return that difference

TC - O(nlogn) + O(nlogklogn)    where k is the max even number in pq and it can be halved max logk times
                                Let's say for n numbers each loop will get executed k times. So, in total loop will get executed O(nlogk) times and for each step push operation will cost O(logn)
                                In total O(nlogklogn)
SC - O(n)
*/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minVal = INT_MAX;
        int minDeviation = INT_MAX;

        // Convert all odd to even & push all numbers to priority_queue to track maximum
        for(int num: nums)
        {
            if(num % 2 == 1)
            {
                num = num * 2;
            }
            pq.push(num);
            minVal = min(num, minVal);
        }
        
        // All numbers will be even when entering this loop for first time
        while(pq.top() % 2 != 1)
        {
            int maxVal = pq.top();
            pq.pop();
            minDeviation = min(minDeviation, maxVal - minVal);
            minVal = min(minVal, maxVal / 2);     // No need to check, as top element was even and that's why loop is being executed
            pq.push(maxVal/ 2);
        }

        minDeviation = min(minDeviation, pq.top() - minVal);
        return minDeviation;
    }
};
