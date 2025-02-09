// https://leetcode.com/problems/count-number-of-bad-pairs/

/*
Approach 1: From 0 to n
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res = 0;
        unordered_map<int, int> dict;
        int n = nums.size();

        // j - i != nums[j] - nums[i] can be written as j - nums[j] != i - nums[i]
        for(int i = 0; i < n; i++)
        {
            int diff = i - nums[i];

            // Default initialization with 0, if diff does not exist in dict
            int goodPairs = dict[diff];     // Pairs for which i < j but j - i == nums[j] - nums[i]
            res += (i - goodPairs);
            dict[diff]++;
        }

        return res;
    }
};


/*
Approach 2: From n to 0
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res = 0;
        unordered_map<int, int> dict;
        int n = nums.size();

        for(int i = n - 1; i >= 0; i--)
        {
            int diff = i - nums[i];
            int goodPairs = dict[diff] + 1;

            res += (n - i - goodPairs);
            dict[diff]++;
        }

        return res;
    }
};
