// https://leetcode.com/problems/permutation-in-string/

// TC - O(n * 26) + O(m) can be written as O(n)
// SC - O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;

        vector<int> targetFreq(26, 0), windowFreq(26, 0);;

        for(const char &ch: s1)
        {
            targetFreq[ch - 'a']++;
        }

        int i = 0, j = 0;
        while(j < s2.size())
        {
            // Process current character freq for window
            windowFreq[s2[j] - 'a']++;

            // If current window size is less than target string's size.
            if(j - i + 1 < s1.size())
            {
                j++;    // Increase window size by one
            }
            else if(j - i + 1 == s1.size())
            {
                // Check if our target string is found
                if(targetFreq == windowFreq)
                    return true;

                // Remove the first character of window and slide it one step forward.
                windowFreq[s2[i] - 'a']--;
                i++;    // Decreases window size by 1
                j++;    // Increases window size by 1
            }
        }

        return false;
    }
};
