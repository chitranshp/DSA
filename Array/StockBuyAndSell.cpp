// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minprice = prices[0];
        int maxp = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < minprice)
                minprice = prices[i];

            maxp = max(maxp, prices[i] - minprice);
       }
        
        return maxp;
    }
};
