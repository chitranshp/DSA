// https://leetcode.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string& word, int index = 0) 
    {
        for(int i = 1; i < word.size(); i++)
        {
            //Covers aBCd, AbZ
            if(islower(word[0]) && isupper(word[i]) ||
                isupper(word[1]) != isupper(word[i]))
                    return false;
        }

        return true;
    }
};
