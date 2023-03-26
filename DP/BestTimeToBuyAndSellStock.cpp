// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

/*
TC - O(N)
SC - O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minprice = prices[0];
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            //No point of buying and selling on same day as profit will be 0.
            int cost = prices[i] - minprice;
            maxprofit = max(maxprofit, cost);
            minprice = min(minprice, prices[i]);  //Will be used in calculating profit for future day's.
        }
        
        return maxprofit;
    }
};