// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {

        // If instead of 2, at most k duplicates was asked
        /*
        int flag = 1;       //k - 1
        int duplicates = 0;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[i - 1])
                flag = 2;           //k

            flag--;
            if(flag < 0)
                duplicates++;

            nums[i - duplicates] = nums[i];  
        }
        cout<<duplicates;
        return nums.size() - duplicates;
        */


        int modifiedsize = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            //For each new element, we compare it with our new modified array nums[modifiedsize - 2]
            if(modifiedsize < 2 || nums[i] > nums[modifiedsize - 2])
                nums[modifiedsize++] = nums[i];
        }

        return modifiedsize;
    }
};