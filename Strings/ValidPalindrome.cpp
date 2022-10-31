https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) 
    {
        //cout<<s.length();
        int i = 0, j = s.length();
        while(i < j)
        {
            while(!isalnum(s[i]) && i < j)  
                i++;
            while(!isalnum(s[j]) && i < j)
                j--;
            if(tolower(s[i++]) != tolower(s[j--]))
                return false;
        }
        
        return true;
    }
};

/*

class Solution {
public:
    bool isPalindrome(string s) 
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string str = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(isalnum(s[i]))
            {
                str.push_back(s[i]);
            }
        }
        
        int j = str.length() - 1;
        for(int i = 0; i < str.length()/2; i++)
        {
            if(str[i] != str[j--])
                return false;
        }
        
        return true;
        
    }
};

*/
