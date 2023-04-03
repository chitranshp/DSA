// https://leetcode.com/problems/boats-to-save-people/solutions/

/*
Greedy 2-pointer approach
TC - O(n) + O(nlogn)
SC - Except sort() rest all are of O(1)
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(), people.end());
        int boats = 0;

        //j tracks the heaviest unpaired person.
        int i = 0, j = people.size() - 1;
        while(i <= j)
        {
            //Both people can go
            if(people[i] + people[j] <= limit)
            {
                i++;
                j--;
            }
            else
                j--;    //j will go alone.

            boats++;
        }

        return boats;
    }
};