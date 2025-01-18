// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

/*
TC - O(n) + O(n)
SC - O(n) + O(n) for prefixSum and suffixSum. O(1) for dicts
*/

class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> prefixSum(n, 0), suffixSum(n, 0);
        int prefixDict[26] = {0}, suffixDict[26] = {0};     // To check whether a character is seen or not till now(distinct)

        // suffixSum[i] denotes number of unique characters in string from i to n - 1 index
        for(int i = n - 1; i >= 0; i--)
        {
            char ch = s[i] - 'a';
            suffixSum[i] = (i != n - 1) ? suffixSum[i + 1]: suffixSum[i];
            if(i == n - 1 || suffixDict[ch] == 0)
            {
                 suffixDict[ch] = 1;
                 suffixSum[i]++;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n - 1; i++)
        {
            // prefixSum[i] denotes number of unique characters in string from 0 to i th index.
            int ch = s[i] - 'a';
            prefixSum[i] = (i != 0)? prefixSum[i - 1]: prefixSum[i];
            if(i == 0 || prefixDict[ch] == 0)
            {
                 prefixDict[ch] = 1;
                 prefixSum[i]++;
            }

            if(prefixSum[i] == suffixSum[i + 1])
                cnt++;
        }

        return cnt;
    }
};


/*
No need to store all values for prefixSum, we need current and previous values only.
TC - O(n) + O(n)
SC - O(n) 
*/

class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> suffixSum(n, 0);
        int prefixDict[26] = {0}, suffixDict[26] = {0};     // To check whether a character is seen or not till now(distinct)

        // suffixSum[i] denotes number of unique characters in string from i to n - 1 index
        for(int i = n - 1; i >= 0; i--)
        {
            char ch = s[i] - 'a';
            suffixSum[i] = (i != n - 1) ? suffixSum[i + 1]: suffixSum[i];
            if(i == n - 1 || suffixDict[ch] == 0)
            {
                 suffixDict[ch] = 1;
                 suffixSum[i]++;
            }
        }

        int cnt = 0, prefixSum = 0;
        for(int i = 0; i < n - 1; i++)
        {
            // prefixSum[i] denotes number of unique characters in string from 0 to i th index.
            int ch = s[i] - 'a';
            if(i == 0 || prefixDict[ch] == 0)
            {
                 prefixDict[ch] = 1;
                 prefixSum++;
            }

            // For each index i, check if number of unique characters from 0 to i is equal to 
            // unique characters from i + 1 to n - 1
            if(prefixSum == suffixSum[i + 1])        // Also one substring cannot be empty. Therefore, i = n - 1 is not valid
                cnt++;
        }

        return cnt;
    }
};
