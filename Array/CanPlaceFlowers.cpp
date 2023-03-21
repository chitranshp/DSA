// https://leetcode.com/problems/can-place-flowers/description/

/*
TC - O(N)
SC - O(1)
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int m = flowerbed.size();
        
        for(int i = 0; i < flowerbed.size(); i++)
        {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == m - 1 || flowerbed[i + 1] == 0))
            {
                    n--;
                    flowerbed[i] = 1; 
                    i++; //As, we can't place flower at next index now. With the increment attached with for loop and this one, in total i will be incremented by 2 in this case.
            }
        }
        
        if(n <= 0)
            return true;

        return false;
        
    }
};
