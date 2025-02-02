// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

/*
Dip means nums[i - 1] > nums[i] <= nums[i + 1]
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        bool firstDipFound = false;
        int i = 0, n = nums.size();


        for(i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                firstDipFound = true;
                break;
            }
        }

        // An array which is only sorted and not rotatated will have first element < last element for sure
        // and NO DIP. So, if a dip is found with this condition, we can directly return false as it cannot be sorted
        // nums[0] == nums.back(), that will be checked in next loop because 5 6 7 1 2 5(1 dip) & 5 5 5 5 5 (0 dip)
        if(nums[0] < nums.back() && firstDipFound)
        {
            return false;
        }
        
        // If one dip is found and nums[0] >= nums.back()
        // Then check, if another dip is present or not. If yes, then return false as array cannot be sort and rotated
        // We start from one index ahead of first dip(If found)
        // If no dip was found in first loop, this loop won't be executed
        while(++i < nums.size() - 1)
        {
            if(nums[i] > nums[i + 1])
            {
                return false;
            }
        }
    
        return true;
    }
};

/*
Similar approach. 
Instead of finding two dips separately, we calculate total number of dips in array. And these dips can also be thought of as inversion point in an array.
If array is sorted and rotated(including 0 times), it will have atmost 1 inversion point
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int inversionCount = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] > nums[i + 1])
                inversionCount++;
        }

        // Array is sorted and rotated 0 time
        if(inversionCount == 0)
            return true;

        // Array is sorted and rotated atleast once
        if(inversionCount == 1 && nums[0] >= nums.back())
            return true;

        return false;       // Array is not sorted and rotated
    }
};
