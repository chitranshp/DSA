/* https://www.hackerrank.com/challenges/vector-erase/problem */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, a, b;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    cin>>x>>a>>b;
    vec.erase(vec.begin() + x - 1);
    vec.erase(vec.begin() + a - 1, vec.begin()+ b -1);
    cout<<vec.size()<<"\n";
    for(auto &it : vec)
    {
        cout<<it<<" ";
    }

    return 0;
}