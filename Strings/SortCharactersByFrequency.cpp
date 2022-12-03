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


//Another approach without using Inbuilt sort function and comperator

/*
class Solution {
public:

    string frequencySort(string s) 
    {
        unordered_map<char, int> freq;  //To store character(key) and frequency(Value)
        map<int, string> sortedorder;   //To Store characters(Value) in ascending order of frequency(Key)
        string res = "";

        for(auto &it : s)
            freq[it]++;

        for(auto &it : freq)
            sortedorder[it.second] += it.first;
        
        for(auto it = sortedorder.rbegin(); it != sortedorder.rend(); it++)     //In reverse
        {
            for(auto &c : it->second)
                res += string(it->first, c);
        }
        
        return res;
    }
};
*/
