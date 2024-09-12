// https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int dict[26] = {0};
        int cnt = words.size();

        for(const char &ch: allowed)
            dict[ch - 'a']++;

        for(const string &word: words)
        {
            bool flag = true;
            for(const char &ch: word)
            {
                if(dict[ch - 'a'] == 0)
                {
                    cnt--;
                    break;
                }
            }
        }

        return cnt;
    }
};
