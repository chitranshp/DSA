// https://leetcode.com/problems/sort-the-people/

// TC - O(nlogn + n) 
// SC - O(n)

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> idx(n);
        vector<string> res;

        for(int i = 0; i < n; i++) 
            idx[i] = i;

        sort(idx.begin(), idx.end(), [&] (int a, int b) {
            return heights[a] > heights[b];
        });

        for(int &i: idx)
            res.push_back(names[i]);

        return res;
    }
};
