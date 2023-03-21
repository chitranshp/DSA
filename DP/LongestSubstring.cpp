// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

/*
Tabulation
TC - O(m * n)
SC - O(m * n)
*/

class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int m, int n)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, 0));
        int maxi = 0;
        
        //First(dummy) row & column are already set to 0 as part of initialization.
        for(int i = 0; i <= m; i++)
            dp[i][0] = 0;
            
        for(int j = 0; j <= n; j++)
            dp[0][j] = 0;
            
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxi = max(dp[i][j], maxi);         //To keep track of maximum length.
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return maxi;
    }
};

/*
SpaceOptimization - Only dependent on previous row ie dp[i][j] is dependent on dp[i - 1][j - 1]. If we start filling from right to left, we can avoid overwriting before we are done using a cell's value.
TC - O(m * n)
SC - O(n)
*/

class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int m, int n)
    {
        //vector<vector<int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, 0));
        vector<int> dp(s2.size() + 1, 0);
        int maxi = 0;
        
        //First(dummy) row & column are already set to 0 as part of initialization.
        for(int j = 0; j <= n; j++)
            dp[j] = 0;
            
        for(int i = 1; i <= m; i++)
        {
            for(int j = n; j >= 0; j--)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    dp[j] = dp[j - 1] + 1;
                    maxi = max(dp[j], maxi);
                }
                else
                    dp[j] = 0;
            }
        }
        
        return maxi;
    }
};