// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

/*
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> result(candies.size(), false);

        int maxcandies = *max_element(candies.begin(), candies.end());
        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i] + extraCandies >= maxcandies)
                result[i] = true;
        }

        return result;
    }
};