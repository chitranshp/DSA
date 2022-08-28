#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	    void solve(string S, vector<string>& ans, int index)
	    {
	        if(index >= S.length())
	        {
	            ans.push_back(S);
	            return;
	        }
	        for(int j = index; j < S.length(); j++)
	        {
	            if(j > index && S[j] == S[j-1])
	               continue;
	            swap(S[index], S[j]);
	            solve(S, ans, index + 1);
	            swap(S[index], S[j]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    int index = 0;
		    solve(S, ans, index);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}