// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/submissions/

class Solution {
public:
    // TC O(26 * n) SC O(26)
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        char ch[26];

        // Initalizing each character such that it points to itself.
        for(int i = 0; i < 26; i++)
            ch[i] = 'a' + i;
        
        /*
        In every iteration, we point the character which is greater between s1[i] and s2[i] to the character which is lexicographically smaller. And to deal with the transivity, we also update all other characters which were pointing to the greater character to now point to the smaller one.
        This is similar to union find. Here, we are just using lexical values instead of size or rank.
        */
        for(int i = 0; i < s1.size(); i++)
        {
            char toBeReplaced = max(ch[s1[i] - 'a'], ch[s2[i] - 'a']);
            char ReplacedWith = min(ch[s1[i] - 'a'], ch[s2[i] - 'a']);

            for(int i = 0; i < 26; i++)
                if(ch[i] == toBeReplaced)
                    ch[i] = ReplacedWith;
        }

        for(int i = 0; i < baseStr.size(); i++)
            baseStr[i] = ch[baseStr[i] - 'a'];

        return baseStr;

        
    }
};
