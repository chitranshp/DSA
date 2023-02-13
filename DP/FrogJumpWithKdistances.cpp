// https://practice.geeksforgeeks.org/problems/minimal-cost/1

/* 
  Recursion - In this approach, we will to explore all possible solutions and find the minimum cost. For every step, we will explore k steps and to handle the corner case we will include an additonal conditon that ignore the cases where index - i < 0 (Negative index)
  TC - O((2^n) * k)
  SC - O(1)

*/
class Solution {
  public:
    int helper(vector<int>& h, int k, int index)
    {
        if(index == 0)
            return 0;

        int total = INT_MAX;
        for(int i = 1; i <= k; i++)
        {
            if(index - i >= 0)
            {
                int val = helper(h, k, index - i) + abs(h[index] - h[index - i]);
                total = min(val, total);   
            }
        }
        
        return total;
    }
    int minimizeCost(vector<int>& height, int n, int k) 
    {
        return helper(height, k, n - 1);
    }
};

/*
  Memoization (Top-Down DP approach) 
  TC - O(N * k)
  SC - O(N) + O(N) approximately equal to O(N)
*/ 

class Solution {
  public:
    int helper(vector<int>& h, int k, int index)
    {
        if(index == 0)
            return 0;

        int total = INT_MAX;
        for(int i = 1; i <= k; i++)
        {
            if(index - i >= 0)
            {
                int val = helper(h, k, index - i) + abs(h[index] - h[index - i]);
                total = min(val, total);   
            }
        }
        
        return total;
    }
    int minimizeCost(vector<int>& height, int n, int k) 
    {
        return helper(height, k, n - 1);
    }
};
