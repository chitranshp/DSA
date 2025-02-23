// https://leetcode.com/problems/clear-digits/

/*
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    string clearDigits(string s) {
        string str = "";

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                str.push_back(s[i]);
            else
            {
                str.pop_back();
            }
        }

        return str;
    }
};

/*
TC - O(n)
SC - O(1)
*/

class Solution {
public:
    string clearDigits(string s) {
        
        int numLength = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                s[numLength] = s[i];
                numLength++;
            }
            else
                numLength--;
        }

        //return s.substr(0, numLength);
        s.resize(numLength);
        return s;
    }
};
