//https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int i = s.length() - 1;
        int counter = 0;
        while(s[i] == ' ')              //For skipping trailing zeroes
            i--;
        
        while(i >= 0 && s[i] != ' ')
        {
            counter++;
            i--;
        }    
        
        return counter;
    }
};
