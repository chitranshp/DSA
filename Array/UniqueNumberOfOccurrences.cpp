// https://leetcode.com/problems/unique-number-of-occurrences/description/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        //TC O(N) SC O(m) where m is the number of unique elements in the array
        unordered_map<int, int> um;
        set<int> freq;

        for(int i = 0; i < arr.size(); i++)
            ++um[arr[i]];

        for(auto &it : um)
            if(!freq.insert(it.second).second)        //  //For single value insertion in set, it returns a pair, where first points to the newly inserted element or the already existing element. Whereas the second value is a boolean value which is true, if the element is inserted and false, if the element already existed. 
                return false;

        return true;
    }
};
