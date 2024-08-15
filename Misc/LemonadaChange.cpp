// https://leetcode.com/problems/lemonade-change/

/*
TC - O(n) & SC - O(1)
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for(int &bill: bills)
        {
            if(bill == 5)
                five++;
            else if(bill == 10)
            {
                ten++;
                five--;
            }
            else if(ten > 0)
            {
                ten--;
                five--;
            }
            else 
                five -= 3;

            if(five < 0)
                return false;
        }

        return true;
    }
};
