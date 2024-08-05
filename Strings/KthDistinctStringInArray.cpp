// https://leetcode.com/problems/kth-distinct-string-in-an-array/
// TC - O(n) SC - O(n)

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> um;

        for(string &s: arr)
        {
            um[s]++;
        }

        for(string &s: arr)
        {
            if(um[s] == 1)
            {
                --k;
                if(k == 0)
                    return s;
            }
        }

        return "";
    }
};
