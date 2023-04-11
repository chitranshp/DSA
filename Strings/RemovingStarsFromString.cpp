// https://leetcode.com/problems/removing-stars-from-a-string/description/

class Solution {
public:
    string removeStars(string s) 
    {
        string str = "";
        bool skip = false;
        int n = s.size(), cnt = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '*')
            {
                cnt++;
                skip = true;
            }
            else if(cnt > 0 || skip == true)
            {
                s[i] = '_' ;
                cnt--;
                skip = false;
            }
            else
                str.push_back(s[i]);
        }

        reverse(str.begin(), str.end());
        return str;
    }
};

/*
TC - O(N)
SC - O(N)
*/

class Solution {
public:
    string removeStars(string s) 
    {
        //We will create another string and treat it as a stack. We will insert new valid(non *) characters at end(top) and deleting from end(top) when curr char is '*'
        //Top of the stack(string) will always be the nearest non * char to the left of current character.
        string str = "";
        int n = s.size();

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*')
            {
                str.pop_back();
            }
            else
                str.push_back(s[i]);
        }

        return str;
    }
};