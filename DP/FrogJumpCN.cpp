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
