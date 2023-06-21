/*
TC - O(nlogn + n)
SC - O(n)
*/

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> p;
        vector<string> res(n);

        for(int i = 0; i < names.size(); i++)
            p.push_back(make_pair(heights[i], names[i]));

        // sort(p.rbegin(), p.rend()); Other way of using greater<int> will not work as that is specifically built for integers only.

        sort(p.begin(), p.end(), [&](pair<int, string> p1, pair<int, string> p2)
        {
            return p1.first > p2.first;
        });

        for(int i = 0; i < names.size(); i++)
            res[i] = p[i].second;

        return res;
    }
};