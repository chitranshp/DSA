// https://leetcode.com/problems/lexicographical-numbers/

/*
Each number between 1 to n will be visited/processed once. Therefore, max time complexity will be O(n).
Whereas max recursion depth will be O(log10 n)
Space complexity = O(n) + O(log10 n) can be written as O(n)
*/

class Solution {
public:
    void dfs(int prefix, int &n, vector<int> &res)
    {
        res.push_back(prefix);
        for(int i = 0; i <= 9; i++)
        {
            int num = prefix * 10 + i;
            if(num > n)
                break;
            dfs(num, n, res);
        }  

        return;
    }
    vector<int> lexicalOrder(int n) 
    {    
        vector<int> res;

        int limit = min(n, 9);      // Handles case where n <= 9. So, no need to iterate for digits more than n
        for(int i = 1; i <= limit; i++)
        {
            dfs(i, n, res);
        }

        return res;

    }
};
