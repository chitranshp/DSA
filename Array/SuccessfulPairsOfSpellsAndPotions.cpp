// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

/*
TC - O(nlogn) for sorting + O(nlogn) in binary search
SC - O(1) as we are just manipulating the input to store our result.
*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(), potions.end());   //O(nlogn)
        for(int i = 0; i < spells.size(); i++)  //O(n)
        {
            int low = 0, high = potions.size() - 1;
            
            while(low <= high)      //O(logn)
            {
                int mid = low + (high - low) / 2;
                long temp = spells[i] * (long)potions[mid];
                if(temp >= success)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;      //If no such pair is found at current index, low will be updated as mid + 1.
                    /*
                    If no such pair is found in array, high won't be updated at all and will still have it's original value of potions.end() - 1, and low will keep on increasing and become equal to potions.end(). At this point loop condition 
                    low <= high will become falsea and loop will break.
                    */
                }
            }

            /*
            We can omit this if else and direclty write 
            spells[i] = potions.size() - high - 1; 
            As in the case no such pair is found, high will be equal to it's initial value of potions.size() - 1.
            And potions.size() - (potions.size() - 1) - 1 = 0.
            */
            if(low >= potions.size())       //No such pair found for index i.
                spells[i] = 0;
            else
                spells[i] = potions.size() - high - 1;      //High will point to last element in potions for which product is less than success. ex. For spells[0] = 5, high will be 0 corresponding to potions[0] = 1. In potions we have 4 elements which make given pair with spells[0]. Therefore, number of pairs = 5 - 0 - 1
        }

        return spells;
    }
};