// https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char, string> p2str;
        unordered_map<string, char> str2p;
        string word = "";
        int pindex = 0;     //For tracking pattern 

        stringstream is(s);
        while(is >> word)
        {
            if(str2p.count(word) && str2p[word] != pattern[pindex])
                return false;

            if(p2str.count(pattern[pindex]) && p2str[pattern[pindex]] != word)
                return false;
            else
            {
                p2str[pattern[pindex]] = word;
                str2p[word] = pattern[pindex];
            }

            pindex++;
        }
        return pindex == pattern.size();
    }
};

/*

class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char, string> um;
        unordered_map<string, char> um2;
        string word = "";
        int pindex = 0;     //For tracking pattern 

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ')
            {
                word.push_back(s[i]);
            }
            if(s[i] == ' ' || i == s.size() - 1)
            {
                if(um2.count(word) && um2[word] != pattern[pindex])
                    return false;

                if(um.find(pattern[pindex]) != um.end())
                {
                    if(um[pattern[pindex]] != word)
                        return false;
                        
                }
                else
                {
                    um[pattern[pindex]] = word;
                    um2[word] = pattern[pindex];
                }

                pindex++;
                word = "";          //Making word empty to make space for next word
            }

        }

        return pindex == pattern.size();
    }
};


*/
