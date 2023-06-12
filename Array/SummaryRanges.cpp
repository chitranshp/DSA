// https://leetcode.com/problems/summary-ranges/description/

/*
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> op;
        int n = nums.size();
        string temp = "";

        for(int i = 0; i < n; i++)
        {
            // i will be fixed and j will move i.e. i will point to beginning of range and j will point to last element of range
            int j = i;
            while(j + 1 < n && nums[j + 1] == nums[j] + 1)  //Checks for a continuous range
                j++;

            if(j > i)       //More than one element exists within our range
            {
                temp += to_string(nums[i]);
                temp += "->";
                temp += to_string(nums[j]);
            }
            else
                temp += to_string(nums[i]); //Only single element exists for that range


            op.push_back(temp);
            i = j;      // For next iteration. Till j, summary range is covered
            temp = "";  // Reinitialization for next iteration
        }
        
        return op;
    }
};