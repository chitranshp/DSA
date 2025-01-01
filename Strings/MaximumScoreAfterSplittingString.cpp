// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

/*
Approach 1: Two pass version
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    int maxScore(string s) 
    {
        int totalZeros = 0, totalOnes = 0;
        for(const char &ch: s)
        {
            if(ch == '0') totalZeros++;
        }

        totalOnes = s.size() - totalZeros;

        if(totalZeros == 0)             // All characters are either all zeroes or all ones.
            return s.size() - 1;

        int maxScore = 0, leftZeros = 0, rightOnes = totalOnes;

        // Traverse upto second last split to consider all valid splits. Split with empty left or right subsplit is invalid
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] == '0')
            {
                leftZeros++;
            }
            else
            {
                rightOnes--;
            }

            maxScore = max(maxScore, leftZeros + rightOnes);
        }

        return maxScore;
    }
};

/*
maxscore = max(leftzeros + rightOnes) 
         = max(leftZeros + 0 + rightOnes)
         = max(leftZeros - leftOnes + leftOnes + rightOnes)
         = max(leftZeros - leftOnes + totalOnes) 
         = max(leftZeros - leftOnes) + totalOnes as totalOnes will be constant

TC = O(n)
SC = O(n)
*/

class Solution {
public:
    int maxScore(string s) 
    {
        int totalOnes = 0;
        int maxScore = INT_MIN;
        int leftZeros = 0, leftOnes = 0;

        // Traverse upto last VALID split to consider all valid splits. Split with empty left or right subsplit is invalid
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] == '0')
            {
                leftZeros++;
            }
            else
            {
                leftOnes++;
            }

            maxScore = max(maxScore, leftZeros - leftOnes);
        }

        totalOnes = leftOnes + (s.back() == '1'? 1: 0);
        return maxScore + totalOnes;
    }
};
