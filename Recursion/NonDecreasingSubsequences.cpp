//https://leetcode.com/problems/non-decreasing-subsequences/description/

/*
Why not DP?
Here we are not bothered about the min/max length of such subsequence. We have to print all such subseqeuences.
To print, we have to go through(generate) all such subsequences first. 
And the best way to generate all possible combinations is to use recursion. We are doing backtracking so that we can use same copy of data(temp and res) instead of copying for each call.
*/

/*
DFS(Recusion) + Backtracking
TC - Exponential O(2 ^ N)
SC - O(n) + O(2 ^ N)
*/

class Solution {
public:
    void helper(vector<int> &nums, int index, set<vector<int>>& res, vector<int> &temp) 
    { 
        if(temp.size() > 1)
            res.insert(temp);

        if(index >= nums.size())
            return;

        for(int i = index; i < nums.size(); i++)
        {
            if(temp.size() == 0 || nums[i] >= temp.back())
            {
                temp.push_back(nums[i]);
                helper(nums, i + 1, res, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        set<vector<int>> setOfVectors;
        vector<int> temp;
        helper(nums, 0, setOfVectors, temp);
        return vector(setOfVectors.begin(), setOfVectors.end());
    }
};

/*
In previous approach, we are using set which has O(logn) time complexity for insertion and is costlier data structure.
To reduce both time and space requiremetns, we can keep using vector of vectors for storing our final answer and a 
separate unordered_set to prevent duplicate subsequences

Although overall, rough complexities will remain same
DFS(Recusion) + Backtracking
TC - Exponential O(2 ^ N)
SC - O(n) + O(2 ^ N)
*/

class Solution 
{
public:
    void helper(vector<int> &nums, int index, vector<vector<int>>& res, vector<int> &temp) 
    { 
        //We are inserting the subsequence, as soon as we get one.
        //This is placed before next condition because, if index == n, there might still be one unstored(new) subsequence contiaining the last element. If we return before storing it, we might miss such subsequences.
        //Notice, we are not returning after this, we will just storing the subsequence and then continue finding the any other subsequence which contain this one.
        if(temp.size() > 1)
            res.push_back(temp);

        if(index >= nums.size())
            return;

        //This is to prevent two subsequences [4, 6, 7(1)] and [4, 6, 7(2)] for a array [4, 6,7, 7]. For index i = 2, it will generate the subsequences recursively and store it. After all the recursive calls are done, it will pop all the elments and temp will [4, 6]. Then it will check whether 7 has been inserted previously at the same positon, then it won't process it and go to i + 1.
        //For each value of 'i' there we will be separately tracking duplicates.
        unordered_set<int> duplicates;
        for(int i = index; i < nums.size(); ++i)
        {
            //If subseq is empty or current element is greater then last element of subseq AND that element is not part of any other subsequence at the same position in temp ONLY THEN it will go inside the condition.
            if((temp.size() == 0 || nums[i] >= temp.back()) && duplicates.count(nums[i]) == 0)
            {
                temp.push_back(nums[i]);
                duplicates.insert(nums[i]);
                helper(nums, i + 1, res, temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        helper(nums, 0, res, temp);
        return res;
    }
};