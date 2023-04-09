// https://leetcode.com/problems/longest-string-chain/

/* 
String chain - Each string of this chain differs from it's preceding string in the chain by one character only. Each successive string will have 
one character extra except it, rest characters will be same.

This problem is also same as LCS and Longest divisible subset only the conditon is changing. We will compare the strings that they have the required length(l and l + 1) and all characters are same except one extra in the longer string.
To allow proper compairing, words vector also needs to be sorted in increasing order of length.

TC - O(n * n * l) where l is the length of longest string in words.
SC - O(n)
*/

class Solution {
public:
    //Comparator function for std::sort()
    static bool cmp(string& w1, string& w2) 
    {
        return w1.size() < w2.size();           //In comparators, we can only use <, >
    }

    bool compare(string& words1, string& words2)
    {
        int i = 0, j = 0;

        if(words1.size() != words2.size() + 1)      //If word1 differ by more than 1 character in length, return false.
            return false;

        //words1 will always be greater then words2 and will have one extra character
        //This will run only if the size criterion is satisfied.
        //If word1.size() = 5 and word2.size() = 4 and word1 has 2 characters which are not in word2.
        //At the end of this loop i will be equal to 5 and loop will break whereas j will be equal to 2 which is less than word2.size(4)
        while(i < words1.size())
        {
            if(j < words2.size() && words1[i] == words2[j])
            {
                i++;
                j++;
            }
            else
                i++;        //For that 1 extra character.
        }

        
        //If all the words(except 1 in words1 which is the larger string out of two) do not match, then j will be at index before the last one.
        return i == words1.size() && j == words2.size();
    }

    int longestStrChain(vector<string>& words) 
    {
        int maxi = 1, n = words.size();

        //We only need the length of chain. So, no need of hash and temp vector.
        vector<int> dp(n, 1);       //Initializing with 1 which is the base case. Every string on it's own is a part of 1 membered chain.
        //dp[0] represents the length of longest string chain untill index 0.

        //Sorting because our compare function is compairing strings using length property of the string chains ie successive string differing by 1 character(2nd string has one extra character)
        sort(words.begin(), words.end(), cmp);

        for(int i = 0; i < n; i++)
        {
            // 'j' will be always less then 'i' and words is sorted as per size. Therefore, words[i] will always be greater then
            // words[j] in length
            for(int j = 0; /j < i; j++)  
            {
                if(compare(words[i], words[j]) == true && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                }
            }

            if(dp[i] > maxi)
                maxi = dp[i];
        }

        return maxi;
    }
};