// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

/*
Ex. 'heap' and 'pea'. 
We will find the longest common subsequence between s1 and s2 for this case which is 'ea'.
To keep the number of operations minimum, we won't touch this subsequence.
Now, we will subtract the length of lcs from length of string s1. This gives the number of characters which are either not present in s2 or are present but in a wrong position for ex. 'p'.
Therefore this gives the number of character to be deleted.

Next, we will subtract the length of LCS from length of string s2. This gives the number of characters which need to be inserted in string s1 to make it same as s2.
In short, we can also write it as:
					 len(s1) + len(s2) - 2 * lcs(s1, s2)

If we sum up both number of deletions and insertions, we will get our required answer.
TC - O(N * M)
SC - O(N) + O(N)
*/
class Solution{
	public:
	int findlcs(string &s1, string &s2)
	{
	    int m = s1.size(), n = s2.size();
	    vector<int> prev(n + 1, 0), curr(n + 1, 0);
	    
	    for(int i = 1; i <= m; i++)
	    {
	        for(int j = 1; j <= n; j++)
	        {
	            if(s1[i - 1] == s2[j - 1])
	                curr[j] = 1 + prev[j - 1];
	            else
	                curr[j] = 0 + max(curr[j - 1], prev[j]);
	        }
	        
	        prev = curr;
	    }
	    
	    return prev[n];
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    int LengthOfLcs = findlcs(str1, str2);
	    int CharsToBeDeleted = str1.size() - LengthOfLcs;
	    int CharsToBeInserted = str2.size() - LengthOfLcs;
	    
	    return CharsToBeDeleted + CharsToBeInserted;
	} 
};