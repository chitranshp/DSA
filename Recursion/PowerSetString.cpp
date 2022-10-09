//https://practice.geeksforgeeks.org/problems/power-set4302/1
#include<bits/stdc++.h>
using namespace std;

//Recursion + Backtracking
/*
void solve(string s, string &curr, int index, vector<string> &ans)
{
	if(index == s.length())
	{
	    if(curr == "")
	        return;
	    ans.push_back(curr);
	    return;
	}
	        
	//Include
	curr = curr + s[index];
	solve(s, curr, index + 1, ans);
	//Exlcude
	curr.pop_back();	//Backtrack
	        
	solve(s, curr, index + 1, ans);
 
	return;
}
*/

void solve(string s, string curr, int index, vector<string> &ans)
{
	if(index == s.length())
	{
	    if(curr == "")
	        return;
	    ans.push_back(curr);
	        return;
	}
	        
	//Include
	solve(s, curr + s[index], index + 1, ans);
	//Exlcude
	solve(s, curr, index + 1, ans);
 
	return;
}

vector<string> AllPossibleStrings(string s)
{
	vector<string> ans;
	string curr = "";
	solve(s, curr, 0, ans);
	sort(ans.begin(), ans.end());
	return ans;
}

int main() 
{
    string s = "Morning";
    vector<string> vec = AllPossibleStrings(s);
    for(auto it: vec)
        cout<<it<<"\n";

    return 0;
}