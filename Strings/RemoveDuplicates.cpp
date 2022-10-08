//https://practice.geeksforgeeks.org/problems/remove-duplicates3034/1?page=4&curated[]=1&sortBy=submissions

class Solution{
public:	
		
	string removeDups(string S) 
	{
	    int *ch = new int[26]();
	    string ans = "";
	    
	    for(int i = 0; i < S.size(); i++)
	    {
	        ch[S[i] - 'a']++;
	        if(ch[S[i] - 'a'] <= 1)
	           ans.push_back(S[i]);
	    }
	    
	    return ans;
	}
};