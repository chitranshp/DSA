// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

/* Recursion - At every steps we have 2 options and we are exploring both of them. Therefore, the total time complexity of this approach will be O(2^n) and SC will be O(n) for recursion stack. */

int helper(vector<int> &h, int index)
{
    if(index == 0)
        return 0;

    int left = 0, right = INT_MAX;

    left = helper(h, index - 1) + abs(h[index] - h[index - 1]);
    if(index > 1)
        right = helper(h, index - 2) + abs(h[index] - h[index - 2]);
    
    return min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    return helper(heights, cost, n - 1);
}

/*
In previous approach, we observe that for n = 5
    f(5) = min(f(4) + cost, f(3) + cost)
    f(4) = min(f(3) + cost, f(2) + cost)
    f(3) = min(f(2) + cost, f(1) + cost)
    f(2) = min(f(1) + cost, f(0) + cost)
    f(1) = min(f(0) + cost, 0)
    
There are a lot of repeating subproblems and in recursive approach we are repeatedly calculating the result for all tof them recursively leading to a exponential time complexity.
To overcome this we can store the result of a subproblem everytime we are caluclating it and use it next time when it's needed ie memoization

Time complexity will be O(n) as the number of calls will be in order of n(Linear) and SC will be O(n) for the recursion stack and the additional vector.

*/

int helper(vector<int> &h, vector<int> &cost, int index)
{
    if(index == 0)
        return 0;

    
    if(cost[index] != -1)
        return cost[index];
    
    int right = INT_MAX;
    int left = helper(h, cost, index - 1) + abs(h[index] - h[index - 1]);
    if(index > 1)
        right = helper(h, cost, index - 2) + abs(h[index] - h[index - 2]);

    return cost[index] = min(left, right);      //Storing it 
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> cost(n + 1, -1);
    return helper(heights, cost, n - 1);
}

/*
To eliminate the recursion stack space we can use the Bottom up approach
*/
int frogJump(int n, vector<int> &heights)
{
    vector<int> cost(n + 1, -1);
    cost[0] = 0;
    //cost[1] = abs(heights[1] - heights[0]);

    for(int i = 1; i < heights.size(); i++)
    {
        //cost[i] = min(cost[i - 1] + abs(heights[i] - heights[i - 1]), cost[i - 2] + abs(heights[i] - heights[i - 2]));
        
        int secondstep = INT_MAX;
        int firststep = cost[i - 1] + abs(heights[i] - heights[i - 1]);
        if(i > 1)
            secondstep = cost[i - 2] + abs(heights[i] - heights[i - 2]);

        cost[i] = min(firststep, secondstep);
    }
    
    return cost[n - 1];
}

/* 
If we look closely, we are only using the last 2 steps for each index and the rest are not needed. We can start from 0 and maintain the last 2 steps only to reduce the SC to O(1).
*/

int frogJump(int n, vector<int> &heights)
{
    int prev = 0;
    int prev2, curri;

    for(int i = 1; i < heights.size(); i++)
    {
        int secondstep = INT_MAX;
        int firststep = prev + abs(heights[i] - heights[i - 1]);
        if(i > 1)
            secondstep = prev2 + abs(heights[i] - heights[i - 2]);
        
        curri = min(firststep, secondstep);
        prev2 = prev;
        prev = curri;
    }
    
    return prev;
}
