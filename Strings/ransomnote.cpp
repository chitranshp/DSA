/* https://leetcode.com/problems/ransom-note/ */

/* Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.*/
/* Each letter in magazine can only be used once in ransomNote. */

#include <bits/stdc++.h>

using namespace std;

bool canConstruct(string ransomNote, string magazine) 
{
        unordered_map<char, int> freq;
        for(int i = 0; i < magazine.size(); i++)
        {
            freq[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.size(); i++)
        {
            if(freq[ransomNote[i]] == 0)
                return false;
            else if(freq[ransomNote[i]] > 0)
                freq[ransomNote[i]]--;
        }
       return true;
}

int main()
{
    string ransomNote = "price", magazine ="sprice";
    cout<<canConstruct(ransomNote, magazine);
    return 0;
}