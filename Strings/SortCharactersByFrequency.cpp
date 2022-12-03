// https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
public:

    string frequencySort(string s) 
    {
        unordered_map<char, int> freq;
        for(int i = 0; i < s.size(); i++)
            freq[s[i]]++;
        
        //Lambda function with capture clause as capture by reference
        sort(s.begin(), s.end(), [&](char a , char b)->bool   
        {
            // Without the second part, it's not guarranted that same characters will be grouped together. It will be similar to fcfs
            //Ex. loveleetcode. For this string would have been ".....lolo....." instead of "..lloo...." or "....ooll...."
            return (freq[a] > freq[b] || (freq[a] == freq[b] && b > a));      //a < b or b < a, both are fine
        });

        return s;
    }
};
