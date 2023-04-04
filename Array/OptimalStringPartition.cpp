// https://leetcode.com/problems/optimal-partition-of-string

/*
Greedy approach
TC - O(N ^ 2)
SC - O(26) which is as good as O(1)
*/

class Solution {
public:
    int partitionString(string s) 
    {
        int cnt = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int ch[26] = {0};
            int j = i;
            while(j < s.length() && ch[s[j] - 'a'] == 0)
            {
                ch[s[j] - 'a']++;
                j++;
            }
            cnt++;
            i = j - 1;
        }

        return cnt;
    }
};

/*
Greedy approach:
TC - O(N)
SC - O(26) which is as good as O(1)
*/

class Solution {
public:
    int partitionString(string s) 
    {
        vector<int> lastseen(26, -1);   
        int substrStart = 0;    //First substring has already started at index 0.
        int cnt = 1;            //For First substring 

        for(int i = 0; i < s.length(); i++)
        {
            //If this character has been seen in the current substring. We will add it to a new empty substring.
            /*
            Why >=?
            If i + 1 th char is same as i th char and i th char is also the starting pos of new substring, 
            then lastseen[s[i + 1]] = substrStart = i. 
            In this case, we will have to start a new substring.
            */
            if(lastseen[s[i] - 'a'] >= substrStart)      
            {
                cnt++; 
                substrStart = i;
                lastseen[s[i] - 'a'] = i;
            }
            //Else if this character has not been seen in the current substring, we will just update it's lastseen position, in case we see it again.
            else
                lastseen[s[i] - 'a'] = i;
        }

        return cnt;
    }
};