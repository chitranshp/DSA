// https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        unordered_set<char> vowel {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int fhalfIndex = 0, secondhalfIndex = s.size()/2;
        int fhalfCount = 0, secondhalfCount = 0;

        while(fhalfIndex < secondhalfIndex && secondhalfIndex < s.size())
        {
            if(vowel.count(s[fhalfIndex++]))
                fhalfCount++; 

            if(vowel.count(s[secondhalfIndex++]))
                secondhalfCount++; 
        }

        return fhalfCount == secondhalfCount;

    }
};
