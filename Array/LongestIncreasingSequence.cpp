// https://leetcode.com/problems/longest-consecutive-sequence/

/*
Although there is a nested while loop, each element is visited at most twice: once when checking if it starts a sequence 
and once while counting the length of the sequence. The time complexity for this part remains O(n).

TC - O(n)
SC - O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();

        unordered_set<int> numSet(nums.begin(), nums.end());    // Duplicate elements will be handled by set. ex. [0, 0, 1]
        int maxStreak = 1;

        for(const int &num: nums)
        {
            // Only consider num as the start of a sequence if num-1 is not present
            if(numSet.find(num - 1) == numSet.end())
            {
                int currentStreak = 1;
                int currentNum = num;

                // Count the length of sequence starting from num
                while(numSet.find(currentNum + 1) != numSet.end())
                {
                    currentStreak++;
                    currentNum++;
                }

                maxStreak = max(maxStreak, currentStreak);
            }
        }

        return maxStreak;
    }
};
