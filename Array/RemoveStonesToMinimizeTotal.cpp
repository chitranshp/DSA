// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/
//O(n + klogn)

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        int total = accumulate(piles.begin(), piles.end(), 0);      //O(n)
        priority_queue<int> pq(piles.begin(), piles.end());     //Uses build heap method internally. Therefore, TC O(N)

        while(k--)      //O(klogn)
        {
            int val = pq.top();         //5     O(1)
            pq.pop();

            total -= (val / 2);         //total already has 5. We just deduct floor(5/2) ie 2 from it.
            val -= (val / 2);           //Updated value 5 - 2 = 3
            pq.push(val);               //O(logn)
        }

        
        return total; 
    }
};
