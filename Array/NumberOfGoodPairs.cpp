// https://leetcode.com/problems/number-of-good-pairs/

/*
Approach 1: Check for all pairs sequentially
TC - O(n ^ 2)
SC - O(1)
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] == nums[j])
                {
                    res++;
                }
            }
        }

        return res;
    }
};

/*
Approach 2: Using Hashmap
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> repeatFreq;     // This map will store how many times a number is repeated(appears) while moving from left to right

        // If we are at index i and before it(excluding i th index element) nums[i] is appearing 2 times (say at i = 0 and i = 1), that means there will be 2 pairs having index i such that given property is satisfied i.e. (0, i) and (1, i) where 0 < 1 < i

        for(int &it : nums)
        {
            if(repeatFreq.find(it) != repeatFreq.end())
            {
                res += repeatFreq[it];
                repeatFreq[it]++;
            }
            else
                repeatFreq[it] = 1;
        }

        return res;
    }
};
