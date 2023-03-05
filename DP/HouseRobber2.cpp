// https://www.codingninjas.com/codestudio/problems/house-robber_839733
// TC - O(n) + O(n) approx equal to O(n) and SC O(n)

#include <bits/stdc++.h> 

long long int helper(vector<int>& loot, int n)
{
       
    long long int prev = loot[0], prev2 = 0, curri;
        
    for(int i = 1; i < n - 1; i++)
    {
        long long int pick = loot[i];
        if(i > 1)
            pick += prev2;
                
        long long int notpick = prev;
            
        curri = max(pick, notpick);
        prev2 = prev;
        prev = curri;
    }
        
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{   
        vector<int> withfirst, withlast;
        int n = valueInHouse.size();

        if(n == 1)
            return valueInHouse[0];
        
        //Both first and last houses can never be looted together as they are adjacent in circular manner.
        for(int i = 0; i < n; i++)
        {
            if(i != 0)
                withlast.push_back(valueInHouse[i]);
                
            if(i != n - 1)
                withfirst.push_back(valueInHouse[i]);   
        }
        
        return max(helper(withfirst, n), helper(withlast, n));
}
