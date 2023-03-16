// https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

/*
Printing one out of all possible LCS 
TC - O(m * n) (To find LCS) + O(m + n) (Backtracking and printing the LCS) [In worst case we will travel m rows and n columsn from (m, n) to (0, 0)]
SC - O(m * n) We need to store whole table.
*/

int findLCS(string& s, string& t, vector<vector<int>> &dp, int i, int j)
{
	if(i < 0 || j < 0)
	    return 0;
	            
	if(dp[i][j] != -1)  
	    return dp[i][j];
	            
	if(s[i] == t[j])
	    return dp[i][j] = 1 + findLCS(s, t, dp, i - 1, j - 1);
	else
	    return dp[i][j] = max(findLCS(s, t, dp, i - 1, j), findLCS(s, t, dp, i, j - 1));
}
	    
vector<string> all_longest_common_subsequences(string s, string t)
{
	int m = s.size(), n = t.size();
	vector<vector<int>> dp(m, vector<int> (n, -1));
	int lengthofLCS = findLCS(s, t, dp, m - 1, n - 1);
		    
	string temp;
	for(int c = 0; c < lengthofLCS; c++)
		temp += "$";                        //Dummy string for creating LCS               
		    
	int i = m, j = n, index = lengthofLCS - 1;
    //We will travel from dp[m][n] to the starting cell of our LCS
	while(i > 0 && j > 0)
	{
        //Original strings are 0 indexed
		if(s[i - 1] == t[j - 1])
		{
		    temp[index] = s[i - 1];     //s[i - 1] = t[j - 1]
	        index--;
            i--;
            j--;
        }
		else if(dp[i - 1][j] > dp[i][j - 1])
		    i--;
	    else
            j--;
	}
	cout<<temp;
}
