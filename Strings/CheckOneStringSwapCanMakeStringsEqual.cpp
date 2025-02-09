// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

/*
Approach1: Check if both strings are anagram and along with it make sure that atmost two indices are there where characters differ
TC - O(n)
SC - O(1) as we are using fixed size array of size 26
*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        int dict[26] = {0};

        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
                cnt++;

            dict[s1[i] - 'a']++;
            dict[s2[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++)
        {
            if(dict[i] != 0)
                return false;
        }

        // We know, that s1 and s2 have same characters or are anagram of each other
        // 1 swap means atmost will be there, such that 2 indices s1 and s2 will differ
        return (cnt <= 2)? true: false;     
    }
};

/*
Approach 2: Check only differing indexes, if differing indexes <= 2
TC - O(n)
SC - O(1)
*/


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // Initalising with -1, to signify no mismatch has been found yet. 
        // If 0 is used and first mismatch is found at index 0, it will lead to false result
        int firstDiffereningIndex = -1, secondDifferingIndex = -1;
        int numDiff = 0;

        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                numDiff++;
                if(firstDiffereningIndex == -1)
                    firstDiffereningIndex = i;
                else if(secondDifferingIndex == -1)
                    secondDifferingIndex = i;
                else 
                    return false;       // More than 2 mismatches, won't be possible with 1 swap
            }
        }

        // Special case: Where both strings are already equal. No differences are found. If both indices point to -1, it will lead to error
        // Solution: intialise them with 0 and use numDiff to determine

        if(numDiff == 0 || numDiff == 2 && s1[firstDiffereningIndex] == s2[secondDifferingIndex] && s1[secondDifferingIndex] == s2[firstDiffereningIndex])
            return true;

        return false;  
    }
};
