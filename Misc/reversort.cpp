/* (Google Code Jam 2021 Qualifiers, https://bit.ly/NPTEL-cs99-W01-Mod1-problem */


#include<bits/stdc++.h>
using namespace std;

int reversort(vector<int> &L)
{
   int cost = 0;
   for(int i = 0; i<L.size()-1; i++)
   {
    int m = *min_element(L.begin()+i, L.end());     
    vector<int>::iterator x = find(L.begin()+i, L.end(), m);       
    reverse(L.begin()+i, x+1);
    cost += distance(L.begin(), x) - i + 1;
   }
   return cost;   
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        std::ios::sync_with_stdio(false);
    #endif
    
    int T,n, num;
    cin>>T;
    for(int c = 0; c<T; c++)
    {
        cin>>n;
        vector<int> L;
        for(int i = 0; i<n; i++)
        {
            cin>>num;
            L.push_back(num);
        }
        cout<<"Case #"<<c+1<<": "<<reversort(L)<<endl;
    }
   return 0;
}
